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

using GuestPtr = std::shared_ptr<Guest>;
using GokartPtr = std::shared_ptr<Gokart>;
using GuestVec = std::vector<GuestPtr>;
using GokartVec = std::vector<GokartPtr>;
using AssignmentMap = std::map<GuestPtr, GokartPtr>;

class Race {
private:
    std::shared_ptr<Map> _map;
    GuestVec _racers;
    GuestVec _validatedGroup;
    GokartVec _availableGokarts;
    AssignmentMap _assignments;
    TrackLead _trackLead;
    bool _isStarted;

public:
    Race(std::shared_ptr<Map> map, TrackLead lead)
            : _map(std::move(map)), _trackLead(std::move(lead)), _isStarted(false) {}

    void addGokarts(const GokartVec &gokarts);

    bool assignGokart(const GuestPtr &guest, GokartType preferredType);

    void performMaintenanceOnAssignedGokarts();

    void startRace();

    void finishRace();

    void addRacer(GuestPtr racer);

    void removeRacer(const std::string &name);

    void setValidatedGroup(const GuestVec &group);

    void clearValidatedGroup();

    [[nodiscard]] std::shared_ptr<Map> getMap() const { return _map; }

    [[nodiscard]] const TrackLead &getTrackLead() const { return _trackLead; }

    [[nodiscard]] const auto &getRacers() const { return _racers; }

    [[nodiscard]] const auto &getValidatedGroup() const { return _validatedGroup; }

    [[nodiscard]] bool isStarted() const { return _isStarted; }

    [[nodiscard]] GokartVec getAvailableGokarts() const {
        return _availableGokarts;
    };

    [[nodiscard]] const auto &getAssignments() const { return _assignments; }
};

#endif // GOKART_RACE_H