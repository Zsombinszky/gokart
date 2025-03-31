#include "RaceGokart.h"
#include <iostream>
#include <sstream>

RaceGokart::RaceGokart(std::string serial, int speed, int power, bool sportMode,
                       EngineType engine, bool turboBoost, bool overtakeSign)
        : BigGokart(std::move(serial), speed, power, sportMode, engine),
          _hasTurboBoost(turboBoost), _hasOvertakeSign(overtakeSign) {}

void RaceGokart::performMaintenance() {
    BigGokart::performMaintenance();  // First do base maintenance
    _hasTurboBoost = true;
    _hasOvertakeSign = true;
    std::cout << "Race features reset\n";
}

std::string RaceGokart::getSpecialFeatures() const {
    std::ostringstream oss;
    oss << BigGokart::getSpecialFeatures();
    if (_hasTurboBoost) oss << " | Turbo-Boost";
    if (_hasOvertakeSign) oss << " | Overtake-Sign";
    return oss.str();
}

bool RaceGokart::hasTurboBoost() const { return _hasTurboBoost; }

bool RaceGokart::hasOvertakeSign() const { return _hasOvertakeSign; }

void RaceGokart::setTurboBoost(bool has) { _hasTurboBoost = has; }

void RaceGokart::setOvertakeSign(bool has) { _hasOvertakeSign = has; }
