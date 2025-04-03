#include <algorithm>
#include "TrackLead.h"

std::vector<std::shared_ptr<Guest>> TrackLead::createGroupBySkill(
        const std::vector<std::shared_ptr<Guest>> &guests,
        SkillLevel skillLevel, int groupSize) {

    if (guests.empty()) {
        throw std::runtime_error("Guests list is empty");
    }

    std::vector<std::shared_ptr<Guest>> group;
    group.reserve(groupSize > 0 ? groupSize : guests.size());

    for (const auto &guest: guests) {
        if (guest && guest->getSkillLevel() == skillLevel) {
            group.push_back(guest);
            if (groupSize > 0 && group.size() >= groupSize) {
                break;
            }
        }
    }

    if (group.empty()) {
        throw std::runtime_error("Could not find any guests skill level");
    }

    return group;
}

std::vector<std::shared_ptr<Guest>> TrackLead::createGroupByAgeRange(
        const std::vector<std::shared_ptr<Guest>> &guests,
        int minAge, int maxAge, int groupSize) {

    if (guests.empty()) {
        throw std::runtime_error("Guests list is empty");
    }

    if (minAge > maxAge) {
        throw std::invalid_argument("Minimum age cannot exceed maximum age");
    }

    std::vector<std::shared_ptr<Guest>> group;
    group.reserve(groupSize > 0 ? groupSize : guests.size());

    std::copy_if(guests.begin(), guests.end(), std::back_inserter(group),
                 [minAge, maxAge, groupSize, &group](const auto &guest) {
                     return guest &&
                            guest->getAge() >= minAge &&
                            guest->getAge() <= maxAge &&
                            (groupSize <= 0 || group.size() < groupSize);
                 });

    if (group.empty()) {
        throw std::runtime_error(
                "No guests found in age range " + std::to_string(minAge) +
                "-" + std::to_string(maxAge)
        );
    }

    return group;
}

std::vector<std::shared_ptr<Guest>> TrackLead::createGroupByMaxSpeed(
        const std::vector<std::shared_ptr<Guest>> &guests,
        int minSpeed, int maxSpeed, int groupSize) {

    if (guests.empty()) {
        throw std::runtime_error("Guests list is empty");
    }

    if (minSpeed > maxSpeed) {
        throw std::invalid_argument("Minimum speed cannot exceed maximum speed");
    }

    std::vector<std::shared_ptr<Guest>> group;
    group.reserve(groupSize > 0 ? groupSize : guests.size());

    for (const auto &guest: guests) {
        if (guest && guest->getMaximumSpeedLevel() >= minSpeed
            && guest->getMaximumSpeedLevel() <= maxSpeed) {
            group.push_back(guest);
            if (groupSize > 0 && group.size() >= groupSize) {
                break;
            }
        }
    }

    if (group.empty()) {
        throw std::runtime_error(
                "No guests found in speed range " + std::to_string(minSpeed) +
                "-" + std::to_string(maxSpeed)
        );
    }

    return group;
}

bool TrackLead::validateGuest(const std::shared_ptr<Guest> &guest) noexcept {
    return guest && guest->getHelmetOn() && guest->getMaskOn();
}