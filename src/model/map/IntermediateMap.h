#ifndef GOKART_INTERMEDIATEMAP_H
#define GOKART_INTERMEDIATEMAP_H

#include "Map.h"
#include <vector>

class IntermediateMap : public Map {
private:
    int _obstacleCount;
    bool _hasShortcuts;
    static const std::vector<std::string> DEFAULT_CHECKPOINTS;
    static constexpr int DEFAULT_MAX_RACERS = 8;
    static constexpr int DEFAULT_OBSTACLES = 5;

public:
    explicit IntermediateMap(std::string name, int maxRacers = DEFAULT_MAX_RACERS, int obstacles = DEFAULT_OBSTACLES,
                             bool shortcuts = true);

    [[nodiscard]] std::vector<std::string> getCheckpoints() const override;

    [[nodiscard]] int getObstacleCount() const noexcept { return _obstacleCount; }

    [[nodiscard]] bool hasShortcuts() const noexcept { return _hasShortcuts; }

    void setObstacleCount(int count);

    void enableShortcuts(bool enabled) noexcept { _hasShortcuts = enabled; }
};

#endif // GOKART_INTERMEDIATEMAP_H