#ifndef GOKART_MAP_H
#define GOKART_MAP_H

#include <string>
#include <vector>
#include "../enum/MapDifficulty.h"

class Map {
protected:
    std::string _name;
    MapDifficulty _difficulty;
    int _maxRacers;

    virtual ~Map() = default;

public:
    Map(std::string name, MapDifficulty difficulty, int maxRacers)
            : _name(std::move(name)), _difficulty(difficulty), _maxRacers(maxRacers) {}

    [[nodiscard]] virtual std::vector<std::string> getCheckpoints() const = 0;

    [[nodiscard]] std::string getName() const noexcept { return _name; }

    [[nodiscard]] MapDifficulty getDifficulty() const noexcept { return _difficulty; }

    [[nodiscard]] int getMaxRacers() const noexcept { return _maxRacers; }
};

#endif // GOKART_MAP_H