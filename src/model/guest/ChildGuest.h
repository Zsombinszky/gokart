#ifndef GOKART_CHILDGUEST_H
#define GOKART_CHILDGUEST_H

#include "Guest.h"
#include "../enum/Color.h"
#include <stdexcept>

class ChildGuest : public Guest {
public:
    // Constructor declaration
    ChildGuest(std::string fullName, std::string nickName, int age,
               int height, SkillLevel skill, Color favColor);

    [[nodiscard]] bool canDrive(GokartType type) const override;

    [[nodiscard]] Color getFavouriteColor() const;

    void setFavouriteColor(Color favouriteColor);

    void somePureVirtual() override;

protected:
    // Age validation helper
    [[nodiscard]] int validateAge(int age) const override;

    [[nodiscard]] int validateHeight(int height) const override;

private:
    static constexpr int MIN_AGE = 5;
    static constexpr int MAX_AGE = 12;
    static constexpr int MIN_HEIGHT_CM = 100;
    static constexpr int MAX_HEIGHT_CM = 160;
    Color favouriteColor;
};

#endif // GOKART_CHILDGUEST_H