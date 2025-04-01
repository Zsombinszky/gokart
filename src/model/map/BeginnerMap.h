#ifndef GOKART_BEGINNERMAP_H
#define GOKART_BEGINNERMAP_H

#include "Map.h"
#include <vector>

class BeginnerMap : public Map {
private:
    static constexpr int BEGINNER_MAX_RACERS = 6;
    static constexpr int BEGINNER_SPEED_LIMIT = 20;
    bool _hasSafetyBarriers;
    int _maxSpeedLimit;
    static const std::vector<std::string> DEFAULT_CHECKPOINTS;

public:
    explicit BeginnerMap(std::string name, int maxRacers = BEGINNER_MAX_RACERS, bool safetyBarriers = true,
                         int speedLimit = BEGINNER_SPEED_LIMIT);

    [[nodiscard]] std::vector<std::string> getCheckpoints() const override;

    [[nodiscard]] bool hasSafetyBarriers() const noexcept { return _hasSafetyBarriers; }

    [[nodiscard]] int getMaxSpeedLimit() const noexcept { return _maxSpeedLimit; }

    void setSafetyBarriers(bool enabled) { _hasSafetyBarriers = enabled; }

    void setMaxSpeedLimit(int limit);
};

#endif // GOKART_BEGINNERMAP_H