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
}

void Race::addRacer(std::shared_ptr<Guest> racer) {
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

void Race::setValidatedGroup(const std::vector<std::shared_ptr<Guest>> &group) {
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

void Race::addGokarts(const std::vector<std::shared_ptr<Gokart>> &karts) {
    if (_isStarted) {
        throw std::runtime_error("Cannot add karts after race started");
    }
    if(karts.empty()){
        throw std::invalid_argument("karts vector is empty! cant add karts");
    }
    _availableGokarts.insert(_availableGokarts.end(), karts.begin(), karts.end());
}

bool Race::assignGokart(const std::shared_ptr<Guest> &guest, GokartType preferredType) {
    if (_isStarted) {
        throw std::runtime_error("Cannot assign karts after race started");
    }
    if (!guest) throw std::invalid_argument("Invalid guest");

    for (size_t i = 0; i < _availableGokarts.size(); i++) {
        if (_availableGokarts[i]->getType() == preferredType) {
            _assignments[guest] = _availableGokarts[i];
            _availableGokarts.erase(_availableGokarts.begin() + i);
            return true;
        }
    }
    return false;
}

void Race::performMaintenanceOnAllGokarts() {
    for (auto &gokart: _availableGokarts) {
        gokart->performMaintenance();
    }
    for (auto &[guest, gokart]: _assignments) {
        gokart->performMaintenance();
    }
}