#ifndef GOKART_INTERMEDIATEMAP_H
#define GOKART_INTERMEDIATEMAP_H

#include "Map.h"
#include <vector>

class IntermediateMap : public Map {
private:
    int _obstacleCount;
    bool _hasShortcuts;

public:
    explicit IntermediateMap(std::string name, int maxRacers = 6, int obstacles = 5, bool shortcuts = true);

    [[nodiscard]] std::vector<std::string> getCheckpoints() const override;

    [[nodiscard]] int getObstacleCount() const { return _obstacleCount; }

    [[nodiscard]] bool hasShortcuts() const { return _hasShortcuts; }

    void setObstacleCount(int count) { _obstacleCount = count; }

    void enableShortcuts(bool enabled) { _hasShortcuts = enabled; }
};

#endif // GOKART_INTERMEDIATEMAP_H