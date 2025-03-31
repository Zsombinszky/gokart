#include "ProMap.h"

ProMap::ProMap(std::string name, int maxRacers, bool nightMode, bool dynamicWeather)
        : Map(std::move(name), MapDifficulty::Hard, maxRacers),
          _nightMode(nightMode),
          _dynamicWeather(dynamicWeather) {}

std::vector<std::string> ProMap::getCheckpoints() const {
    return {
            "Start Grid",
            "Hairpin Turn",
            "Elevation Change",
            "The Corkscrew",
            "Pit Straight",
            "Final Showdown",
            "Finish Line"
    };
}