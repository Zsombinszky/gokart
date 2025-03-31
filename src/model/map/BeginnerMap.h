#ifndef GOKART_BEGINNERMAP_H
#define GOKART_BEGINNERMAP_H

#include "Map.h"
#include <vector>

class BeginnerMap : public Map {
private:
    bool _hasSafetyBarriers;
    int _maxSpeedLimit;

public:
    explicit BeginnerMap(std::string name, int maxRacers = 8, bool safetyBarriers = true, int speedLimit = 40);

    [[nodiscard]] std::vector<std::string> getCheckpoints() const override;

    [[nodiscard]] bool hasSafetyBarriers() const { return _hasSafetyBarriers; }

    [[nodiscard]] int getMaxSpeedLimit() const { return _maxSpeedLimit; }

    void setSafetyBarriers(bool enabled) { _hasSafetyBarriers = enabled; }

    void setMaxSpeedLimit(int limit) { _maxSpeedLimit = limit; }
};

#endif // GOKART_BEGINNERMAP_H