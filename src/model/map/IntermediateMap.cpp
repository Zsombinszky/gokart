#include "IntermediateMap.h"

IntermediateMap::IntermediateMap(std::string name, int maxRacers, int obstacles, bool shortcuts)
        : Map(std::move(name), MapDifficulty::Medium, maxRacers),
          _obstacleCount(obstacles),
          _hasShortcuts(shortcuts) {}

std::vector<std::string> IntermediateMap::getCheckpoints() const {
    return {
            "Start Line",
            "S-Curve Section",
            "Obstacle Alley",
            "High-Speed Straight",
            "Technical Chicane",
            "Finish Line"
    };
}