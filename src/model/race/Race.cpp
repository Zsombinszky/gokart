#include "Race.h"
#include <algorithm>
#include <iostream>

void Race::startRace() {
    if (_validatedGroup.empty()) {
        throw std::runtime_error("Cannot start race - no validated group");
    }
    _isStarted = true;
    std::cout << "Race on " << _map->getName() << " has started with "
              << _validatedGroup.size() << " racers!\n";
}

void Race::finishRace() {
    _isStarted = false;
    _assignments.clear();
    clearValidatedGroup();
}

void Race::addRacer(GuestPtr racer) {
    if (_isStarted) {
        throw std::runtime_error("Cannot add racer after race started");
    }
    if (!racer) throw std::invalid_argument("Invalid racer");
    if (std::find(_racers.begin(), _racers.end(), racer) != _racers.end()) {
        throw std::runtime_error("Racer already added");
    }

    _racers.push_back(std::move(racer));
}

void Race::removeRacer(const std::string &name) {
    if (_isStarted) {
        throw std::runtime_error("Cannot remove racer after race started");
    }
    _racers.erase(
            std::remove_if(_racers.begin(), _racers.end(),
                           [&name](const std::shared_ptr<Guest> &racer) {
                               return racer && racer->getFullName() == name;
                           }),
            _racers.end()
    );
}

void Race::setValidatedGroup(const GuestVec &group) {
    if (_isStarted) {
        throw std::runtime_error("Cannot set group after race started");
    }
    _validatedGroup = group;
}

void Race::clearValidatedGroup() {
    if (_isStarted) {
        throw std::runtime_error("Cannot clear group after race started");
    }
    _validatedGroup.clear();
}

void Race::addGokarts(const GokartVec &karts) {
    if (_isStarted) {
        throw std::runtime_error("Cannot add karts after race started");
    }
    if (karts.empty()) {
        throw std::invalid_argument("karts vector is empty! cant add karts");
    }
    _availableGokarts.insert(_availableGokarts.end(), karts.begin(), karts.end());
}

bool Race::assignGokart(const GuestPtr &guest, GokartType preferredType) {
    if (_isStarted) {
        throw std::runtime_error("Cannot assign karts after race started");
    }
    if (!guest) throw std::invalid_argument("Invalid guest");
    if (!guest->canDrive(preferredType)) {
        throw std::runtime_error("Guest cant drive the preferred type kart!");
    }

    for (size_t i = 0; i < _availableGokarts.size(); i++) {
        const auto gokart = _availableGokarts[i];
        if (gokart->getType() != preferredType) {
            continue;
        }
        _assignments[guest] = _availableGokarts[i];
        _availableGokarts.erase(_availableGokarts.begin() + i);
        return true;
    }
    return false;
}

void Race::performMaintenanceOnAssignedGokarts() {
    for (auto &[guest, gokart]: _assignments) {
        gokart->performMaintenance();
    }
}