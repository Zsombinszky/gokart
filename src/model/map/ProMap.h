#ifndef GOKART_PROMAP_H
#define GOKART_PROMAP_H

#include "Map.h"
#include <vector>

class ProMap : public Map {
private:
    bool _nightMode;
    bool _dynamicWeather;
    static const std::vector<std::string> DEFAULT_CHECKPOINTS;
    static constexpr int DEFAULT_MAX_RACERS = 10;

public:
    explicit ProMap(std::string name, int maxRacers = DEFAULT_MAX_RACERS, bool nightMode = false,
                    bool dynamicWeather = false);

    [[nodiscard]] std::vector<std::string> getCheckpoints() const override;

    [[nodiscard]] bool isNightMode() const noexcept{ return _nightMode; }

    [[nodiscard]] bool hasDynamicWeather() const noexcept{ return _dynamicWeather; }

    void setNightMode(bool enabled) { _nightMode = enabled; }

    void setDynamicWeather(bool enabled) { _dynamicWeather = enabled; }
};

#endif // GOKART_PROMAP_H