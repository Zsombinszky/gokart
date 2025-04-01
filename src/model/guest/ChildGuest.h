#ifndef GOKART_CHILDGUEST_H
#define GOKART_CHILDGUEST_H

#include "Guest.h"
#include "../enum/Color.h"
#include <stdexcept>

class ChildGuest : public Guest {
public:
    ChildGuest(std::string fullName, std::string nickName, int age,
               int height, SkillLevel skill, Color favColor);

    [[nodiscard]] bool canDrive(GokartType type) const override;

    [[nodiscard]] Color getFavouriteColor() const noexcept;

    void setFavouriteColor(Color favouriteColor) noexcept;

protected:
    [[nodiscard]] int validateAge(int age) const override;

    [[nodiscard]] int validateHeight(int height) const override;

private:
    static constexpr int MIN_AGE = 5;
    static constexpr int MAX_AGE = 12;
    static constexpr int MIN_HEIGHT_CM = 100;
    static constexpr int MAX_HEIGHT_CM = 160;
    static constexpr int MIN_AGE_FOR_BIG_KART = 10;
    Color favouriteColor;
};

#endif // GOKART_CHILDGUEST_H