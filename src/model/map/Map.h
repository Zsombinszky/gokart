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

public:
    Map(std::string name, MapDifficulty difficulty, int maxRacers)
            : _name(std::move(name)), _difficulty(difficulty), _maxRacers(maxRacers) {}

    virtual ~Map() = default;

    [[nodiscard]] virtual std::vector<std::string> getCheckpoints() const = 0;

    [[nodiscard]] std::string getName() const { return _name; }

    [[nodiscard]] MapDifficulty getDifficulty() const { return _difficulty; }

    [[nodiscard]] int getMaxRacers() const { return _maxRacers; }
};

#endif // GOKART_MAP_H