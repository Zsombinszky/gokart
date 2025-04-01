#include "ProMap.h"

const std::vector<std::string> ProMap::DEFAULT_CHECKPOINTS = {
        "Pro Start",
        "Precision Corner",
        "Danger S-Bend",
        "Full-Throttle Straight",
        "Extreme Chicane",
        "Championship Finish"
};

ProMap::ProMap(std::string name, int maxRacers, bool nightMode, bool dynamicWeather)
        : Map(std::move(name), MapDifficulty::Hard, maxRacers),
          _nightMode(nightMode),
          _dynamicWeather(dynamicWeather) {}

std::vector<std::string> ProMap::getCheckpoints() const {
    return DEFAULT_CHECKPOINTS;
}