#ifndef GOKART_TRACKLEAD_H
#define GOKART_TRACKLEAD_H

#include <string>
#include <vector>
#include <memory>
#include "../guest/Guest.h"

class TrackLead {
private:
    std::string _name;
    bool _hasAidkit;
    bool _hasThreeFlag;

public:
    TrackLead(std::string name, bool aidKit = true, bool threeFlag = true)
            : _name(std::move(name)), _hasAidkit(aidKit), _hasThreeFlag(threeFlag) {}

    [[nodiscard]] std::string getName() const { return _name; }

    [[nodiscard]] bool hasAidKit() const { return _hasAidkit; }

    [[nodiscard]] bool hasThreeFlag() const { return _hasThreeFlag; }

    void setAidKit(bool has) { _hasAidkit = has; }

    void setThreeFlag(bool has) { _hasThreeFlag = has; }

    [[nodiscard]] static std::vector<std::shared_ptr<Guest>>
    createGroupBySkill(const std::vector<std::shared_ptr<Guest>> &guests, SkillLevel skillLevel, int groupSize);

    [[nodiscard]] static std::vector<std::shared_ptr<Guest>>
    createGroupByAgeRange(const std::vector<std::shared_ptr<Guest>> &guests, int minAge, int maxAge, int groupSize);

    [[nodiscard]] static std::vector<std::shared_ptr<Guest>>
    createGroupByMaxSpeed(const std::vector<std::shared_ptr<Guest>> &guests, int minAge, int maxAge, int groupSize);

    bool static validateGuest(const std::shared_ptr<Guest> &guest);

};

#endif // GOKART_TRACKLEAD_H