#include <sstream>
#include <iostream>
#include "BigGokart.h"

void BigGokart::performMaintenance() {
    _enginePower = 15;
    _hasRollCage = true;
    _hasSportMode = true;

    std::cout << "BigGokart " << getSerialNumber()
              << " maintenance completed. Reset to factory specs.\n";
}

std::string BigGokart::getSpecialFeatures() const {
    std::ostringstream oss;
    oss << toString(_engineType) << " " << _enginePower << "HP";
    if (_hasSportMode) {
        oss << " (Sport Mode)";
    }
    if (_hasRollCage) {
        oss << " [Roll Cage]";
    }
    return oss.str();
}

bool BigGokart::hasRollCage() const {
    return _hasRollCage;
}

bool BigGokart::hasSportMode() const {
    return _hasSportMode;
}

EngineType BigGokart::getEngineType() const {
    return _engineType;
}

int BigGokart::getEnginePower() const {
    return _enginePower;
}

void BigGokart::setRollCage(bool has) {
    _hasRollCage = has;
}

void BigGokart::setEnginePower(int power) {
    if (power > 0) {
        _enginePower = power;
    }
}

void BigGokart::setSportMode(bool sport) {
    _hasSportMode = sport;
}

void BigGokart::setEngineType(EngineType engine) {
    _engineType = engine;
}
