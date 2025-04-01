#ifndef GOKART_SMALLGOKART_H
#define GOKART_SMALLGOKART_H

#include "Gokart.h"

class SmallGokart final : public Gokart {
private:
    static constexpr int BASE_SMALLGOKART_SPEED = 40;
    bool _hasExtraFoamProtection;
    bool _hasFluffySteeringWheel;
    bool _hasFunnyHonk;
    bool _hasSafetyFlag;

public:
    explicit SmallGokart(std::string serial, int speed = BASE_SMALLGOKART_SPEED)
            : Gokart(std::move(serial), speed, GokartType::Small),
              _hasExtraFoamProtection(true),
              _hasFluffySteeringWheel(true),
              _hasFunnyHonk(true),
              _hasSafetyFlag(true) {}

    void performMaintenance() override;

    [[nodiscard]] std::string getSpecialFeatures() const override;

    [[nodiscard]] bool hasFluffySteeringWheel() const noexcept;

    [[nodiscard]] bool hasFunnyHonk() const noexcept;

    [[nodiscard]] bool hasExtraFoamProtection() const noexcept;

    [[nodiscard]] bool hasSafetyFlag() const noexcept;

    void setSafetyFlag(bool has);

    void setFunnyHonk(bool has);

    void setFluffySteeringWheel(bool has);

    void setExtraFoamProtection(bool has);
};

#endif // GOKART_SMALLGOKART_H
