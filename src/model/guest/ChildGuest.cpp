#include "ChildGuest.h"

ChildGuest::ChildGuest(std::string fullName, std::string nickName, int age,
                       int height, SkillLevel skill, Color favColor)
        : Guest(std::move(fullName),
                std::move(nickName),
                validateAge(age),
                validateHeight(height),
                skill), favouriteColor(favColor) {}

void ChildGuest::somePureVirtual() {
}

bool ChildGuest::canDrive(GokartType type) const {
    switch (type) {
        case GokartType::Small:
            return true;
        case GokartType::Big:
            return (skillLevel == SkillLevel::Advanced ||
                    skillLevel == SkillLevel::Pro) &&
                   age >= 10;
        case GokartType::Race:
            return false;
        default:
            return false;
    }
}

int ChildGuest::validateAge(int age) const {
    if (age < MIN_AGE || age > MAX_AGE) {
        throw std::invalid_argument(
                "Child age must be between " +
                std::to_string(MIN_AGE) + "-" +
                std::to_string(MAX_AGE)
        );
    }
    return age;
}

int ChildGuest::validateHeight(int height) const {
    if (height < MIN_HEIGHT_CM || height > MAX_HEIGHT_CM) {
        throw std::invalid_argument(
                "Child height must be between " +
                std::to_string(MIN_HEIGHT_CM) + "cm-" +
                std::to_string(MAX_HEIGHT_CM) + "cm"
        );
    }
    return height;
}

void ChildGuest::setFavouriteColor(Color favouriteColor) {
    ChildGuest::favouriteColor = favouriteColor;
}

Color ChildGuest::getFavouriteColor() const {
    return favouriteColor;
}
