#include "AdultGuest.h"

AdultGuest::AdultGuest(std::string fullName, std::string nickName, int age, int height,
                       SkillLevel skill) : Guest(
        std::move(fullName),
        std::move(nickName),
        validateAge(age),
        validateHeight(height),
        skill) {}

bool AdultGuest::canDrive(GokartType type) const {
    switch (type) {
        case GokartType::Small:
            return this->getHeightInCentimeter() < MAX_HEIGHT_FOR_SMALL_KART;
        case GokartType::Big:
            return true;
        case GokartType::Race:
            return skillLevel == SkillLevel::Pro;
        default:
            return false;
    }
}

int AdultGuest::validateAge(int age) const {
    if (age < MIN_AGE || age > MAX_AGE) {
        throw std::invalid_argument(
                "Adult age must be between " +
                std::to_string(MIN_AGE) + "-" +
                std::to_string(MAX_AGE)
        );
    }
    return age;
}

int AdultGuest::validateHeight(int height) const {
    if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
        throw std::invalid_argument(
                "Adult height must be between " +
                std::to_string(MIN_HEIGHT) + "cm-" +
                std::to_string(MAX_HEIGHT) + "cm"
        );
    }
    return height;
}