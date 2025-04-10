#include "Guest.h"

Guest::Guest(std::string fullName, std::string nickName, int age,
             int heightInCentimeter, SkillLevel skillLevel)
        : fullName(std::move(fullName)),
          nickName(std::move(nickName)),
          age(age),
          heightInCentimeter(heightInCentimeter),
          skillLevel(skillLevel) {
    updateMaximumSpeed();
}

void Guest::updateMaximumSpeed() {
    switch (skillLevel) {
        case SkillLevel::Beginner:
            maximumSpeedLevel = 3;
            break;
        case SkillLevel::Intermediate:
            maximumSpeedLevel = 6;
            break;
        case SkillLevel::Advanced:
            maximumSpeedLevel = 8;
            break;
        case SkillLevel::Pro:
            maximumSpeedLevel = 10;
            break;
    }
}

const std::string &Guest::getFullName() const noexcept {
    return fullName;
}

const std::string &Guest::getNickName() const noexcept {
    return nickName;
}

int Guest::getAge() const noexcept {
    return age;
}

int Guest::getHeightInCentimeter() const noexcept {
    return heightInCentimeter;
}

SkillLevel Guest::getSkillLevel() const noexcept {
    return skillLevel;
}

int Guest::getMaximumSpeedLevel() const noexcept {
    return maximumSpeedLevel;
}

bool Guest::getMaskOn() const noexcept {
    return hasMaskOn;
}

bool Guest::getHelmetOn() const noexcept {
    return hasHelmetOn;
}

void Guest::setNickName(std::string nickName) {
    this->nickName = std::move(nickName);
}

void Guest::setAge(int age) {
    this->age = age;
}

void Guest::setHeightInCentimeter(int heightInCentimeter) {
    this->heightInCentimeter = heightInCentimeter;
}

void Guest::setSkillLevel(SkillLevel skillLevel) {
    this->skillLevel = skillLevel;
    updateMaximumSpeed();
}

void Guest::setHasMaskOn(bool hasMaskOn) {
    this->hasMaskOn = hasMaskOn;
}

void Guest::setHasHelmetOn(bool hasHelmetOn) {
    this->hasHelmetOn = hasHelmetOn;
}