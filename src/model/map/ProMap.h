#ifndef GOKART_PROMAP_H
#define GOKART_PROMAP_H

#include "Map.h"
#include <vector>

class ProMap : public Map {
private:
    bool _nightMode;
    bool _dynamicWeather;

public:
    explicit ProMap(std::string name, int maxRacers = 4, bool nightMode = false, bool dynamicWeather = false);

    [[nodiscard]] std::vector<std::string> getCheckpoints() const override;

    [[nodiscard]] bool isNightMode() const { return _nightMode; }

    [[nodiscard]] bool hasDynamicWeather() const { return _dynamicWeather; }

    void setNightMode(bool enabled) { _nightMode = enabled; }

    void setDynamicWeather(bool enabled) { _dynamicWeather = enabled; }
};

#endif // GOKART_PROMAP_H