#include <sstream>
#include <iostream>
#include "SmallGokart.h"

std::string SmallGokart::getSpecialFeatures() const {
    std::ostringstream features;
    features << "Child-friendly features: ";

    bool hasFeature = false;
    if (_hasExtraFoamProtection) {
        features << "Foam protection";
        hasFeature = true;
    }
    if (_hasFluffySteeringWheel) {
        if (hasFeature) features << ", ";
        features << "Fluffy wheel";
        hasFeature = true;
    }
    if (_hasFunnyHonk) {
        if (hasFeature) features << ", ";
        features << "Funny honk";
        hasFeature = true;
    }
    if (_hasSafetyFlag) {
        if (hasFeature) features << ", ";
        features << "Safety flag";
    }

    return features.str();
}

bool SmallGokart::hasFluffySteeringWheel() const noexcept {
    return _hasFluffySteeringWheel;
}

bool SmallGokart::hasFunnyHonk() const noexcept {
    return _hasFunnyHonk;
}

bool SmallGokart::hasExtraFoamProtection() const noexcept {
    return _hasExtraFoamProtection;
}

bool SmallGokart::hasSafetyFlag() const noexcept {
    return _hasSafetyFlag;
}

void SmallGokart::setSafetyFlag(bool has) {
    _hasSafetyFlag = has;
}

void SmallGokart::setFunnyHonk(bool has) {
    _hasFunnyHonk = has;
}

void SmallGokart::setFluffySteeringWheel(bool has) {
    _hasFluffySteeringWheel = has;
}

void SmallGokart::setExtraFoamProtection(bool has) {
    _hasExtraFoamProtection = has;
}

void SmallGokart::performMaintenance() {
    _hasExtraFoamProtection = true;
    _hasFluffySteeringWheel = true;
    _hasFunnyHonk = true;
    _hasSafetyFlag = true;

    std::cout << "SmallGokart " << getSerialNumber()
              << " maintenance complete - all safety features reset.\n";
}
