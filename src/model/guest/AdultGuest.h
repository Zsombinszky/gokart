#ifndef GOKART_ADULTGUEST_H
#define GOKART_ADULTGUEST_H


#include "Guest.h"
#include <stdexcept>

class AdultGuest : public Guest {
public:
    AdultGuest(std::string fullName, std::string nickName, int age, int height, SkillLevel skill);

    [[nodiscard]] bool canDrive(GokartType type) const override;

protected:
    [[nodiscard]] int validateAge(int age) const override;

    [[nodiscard]] int validateHeight(int height) const override;

private:
    static constexpr int MIN_AGE = 18;
    static constexpr int MAX_AGE = 70;
    static constexpr int MIN_HEIGHT = 140;
    static constexpr int MAX_HEIGHT = 200;
    static constexpr int MAX_HEIGHT_FOR_SMALL_KART = 150;
};


#endif //GOKART_ADULTGUEST_H
