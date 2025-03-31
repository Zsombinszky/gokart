#include "BeginnerMap.h"

BeginnerMap::BeginnerMap(std::string name, int maxRacers, bool safetyBarriers, int speedLimit)
        : Map(std::move(name), MapDifficulty::Easy, maxRacers),
          _hasSafetyBarriers(safetyBarriers),
          _maxSpeedLimit(speedLimit) {}

std::vector<std::string> BeginnerMap::getCheckpoints() const {
    return {
            "Start Line",
            "Easy Turn 1",
            "Straightaway",
            "Final Corner",
            "Finish Line"
    };
}