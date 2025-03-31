#ifndef GOKART_RACE_H
#define GOKART_RACE_H

#include "../map/Map.h"
#include "../staff/TrackLead.h"
#include "../kart/GoKart.h"
#include <utility>
#include <vector>
#include <memory>
#include <map>

class Guest;

class Race {
private:
    std::shared_ptr<Map> _map;
    std::vector<std::shared_ptr<Guest>> _racers;
    std::vector<std::shared_ptr<Guest>> _validatedGroup;
    std::vector<std::shared_ptr<Gokart>> _availableGokarts;
    std::map<std::shared_ptr<Guest>, std::shared_ptr<Gokart>> _assignments;
    TrackLead _trackLead;
    bool _isStarted;

public:
    Race(std::shared_ptr<Map> map, TrackLead lead)
            : _map(std::move(map)), _trackLead(std::move(lead)), _isStarted(false) {}

    void addGokarts(const std::vector<std::shared_ptr<Gokart>> &gokarts);

    bool assignGokart(const std::shared_ptr<Guest> &guest, GokartType preferredType);

    void performMaintenanceOnAllGokarts();

    void startRace();

    void addRacer(std::shared_ptr<Guest> racer);

    void removeRacer(const std::string &name);

    void setValidatedGroup(const std::vector<std::shared_ptr<Guest>> &group);

    void clearValidatedGroup();

    [[nodiscard]] std::shared_ptr<Map> getMap() const { return _map; }

    [[nodiscard]] const TrackLead &getTrackLead() const { return _trackLead; }

    [[nodiscard]] const auto &getRacers() const { return _racers; }

    [[nodiscard]] const auto &getValidatedGroup() const { return _validatedGroup; }

    [[nodiscard]] bool isStarted() const { return _isStarted; }

    [[nodiscard]] std::vector<std::shared_ptr<Gokart>> getAvailableGokarts() const {
        return _availableGokarts;
    };

    [[nodiscard]] const auto &getAssignments() const { return _assignments; }
};

#endif // GOKART_RACE_H