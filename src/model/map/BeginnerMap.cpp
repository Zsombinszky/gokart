#include <stdexcept>
#include "BeginnerMap.h"

const std::vector<std::string> BeginnerMap::DEFAULT_CHECKPOINTS = {
        "Start Line",
        "Easy Turn 1",
        "Straightaway",
        "Final Corner",
        "Finish Line"
};

BeginnerMap::BeginnerMap(std::string name, int maxRacers, bool safetyBarriers, int speedLimit)
        : Map(std::move(name), MapDifficulty::Easy, maxRacers),
          _hasSafetyBarriers(safetyBarriers),
          _maxSpeedLimit(speedLimit) {}

std::vector<std::string> BeginnerMap::getCheckpoints() const {
    return DEFAULT_CHECKPOINTS;
}

void BeginnerMap::setMaxSpeedLimit(int limit) {
    if (limit <= 0) {
        throw std::invalid_argument("Speed limit must be positive");
    }
    _maxSpeedLimit = limit;
}