#include "TrackLead.h"

std::vector<std::shared_ptr<Guest>> TrackLead::createGroupBySkill(
        const std::vector<std::shared_ptr<Guest>> &guests,
        SkillLevel skillLevel, int groupSize) {

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

    return group;
}

std::vector<std::shared_ptr<Guest>> TrackLead::createGroupByAgeRange(
        const std::vector<std::shared_ptr<Guest>> &guests,
        int minAge, int maxAge, int groupSize) {

    std::vector<std::shared_ptr<Guest>> group;
    group.reserve(groupSize > 0 ? groupSize : guests.size());

    for (const auto &guest: guests) {
        if (guest && guest->getAge() >= minAge && guest->getAge() <= maxAge) {
            group.push_back(guest);
            if (groupSize > 0 && group.size() >= groupSize) {
                break;
            }
        }
    }

    return group;
}

std::vector<std::shared_ptr<Guest>> TrackLead::createGroupByMaxSpeed(
        const std::vector<std::shared_ptr<Guest>> &guests,
        int minSpeed, int maxSpeed, int groupSize) {

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

    return group;
}

bool TrackLead::validateGuest(const std::shared_ptr<Guest> &guest) {
    return guest && guest->getHelmetOn() && guest->getMaskOn();
}