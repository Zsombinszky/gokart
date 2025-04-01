#include <stdexcept>
#include "IntermediateMap.h"

const std::vector<std::string> IntermediateMap::DEFAULT_CHECKPOINTS = {
        "Start Line",
        "S-Curve Section",
        "Obstacle Alley",
        "High-Speed Straight",
        "Technical Chicane",
        "Finish Line"
};

IntermediateMap::IntermediateMap(std::string name, int maxRacers, int obstacles, bool shortcuts)
        : Map(std::move(name), MapDifficulty::Medium, maxRacers),
          _obstacleCount(obstacles),
          _hasShortcuts(shortcuts) {}

std::vector<std::string> IntermediateMap::getCheckpoints() const {
    return DEFAULT_CHECKPOINTS;
}

void IntermediateMap::setObstacleCount(int count) {
    if (count < 0) {
        throw std::invalid_argument("Obstacle count cannot be negative");
    }
    _obstacleCount = count;
}