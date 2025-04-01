#ifndef GOKART_GUEST_H
#define GOKART_GUEST_H

#include <string>
#include "../enum/GokartType.h"
#include "../enum/SkillLevel.h"


class Guest {
private:
    std::string fullName;
    std::string nickName;
    int heightInCentimeter = 0;
    int maximumSpeedLevel = 0;
    bool hasMaskOn = false;
    bool hasHelmetOn = false;

    void updateMaximumSpeed();

protected:
    virtual ~Guest() = default;

    SkillLevel skillLevel;
    int age = 0;

    [[nodiscard]] virtual int validateAge(int age) const = 0;

    [[nodiscard]] virtual int validateHeight(int height) const = 0;

public:
    Guest(std::string fullName, std::string nickName, int age, int heightInCentimeter, SkillLevel skillLevel);

    [[nodiscard]] virtual bool canDrive(GokartType type) const = 0;

    [[nodiscard]] const std::string &getFullName() const;

    [[nodiscard]] const std::string &getNickName() const;

    [[nodiscard]] int getAge() const;

    [[nodiscard]] int getHeightInCentimeter() const;

    [[nodiscard]] SkillLevel getSkillLevel() const;

    [[nodiscard]] int getMaximumSpeedLevel() const;

    [[nodiscard]] bool getMaskOn() const;

    [[nodiscard]] bool getHelmetOn() const;

    void setNickName(std::string nickName);

    void setAge(int age);

    void setHeightInCentimeter(int heightInCentimeter);

    void setSkillLevel(SkillLevel skillLevel);

    void setHasMaskOn(bool hasMaskOn);

    void setHasHelmetOn(bool hasHelmetOn);
};

#endif // GOKART_GUEST_H