#ifndef GOKART_RACEGOKART_H
#define GOKART_RACEGOKART_H

#include "BigGokart.h"

class RaceGokart final : public BigGokart {
private:
    static constexpr int BASE_RACEGOKART_SPEED = 100;
    static constexpr int BASE_RACEGOKART_POWER = 25;
    bool _hasTurboBoost;
    bool _hasOvertakeSign;

public:
    explicit RaceGokart(std::string serial, int speed = BASE_RACEGOKART_SPEED, int power = BASE_RACEGOKART_POWER,
                        bool sportMode = true,
                        EngineType engine = EngineType::Gasoline, bool turboBoost = true, bool overtakeSign = true);

    void performMaintenance() override;

    [[nodiscard]] std::string getSpecialFeatures() const override;

    [[nodiscard]] bool hasTurboBoost() const noexcept;

    [[nodiscard]] bool hasOvertakeSign() const noexcept;

    void setTurboBoost(bool has);

    void setOvertakeSign(bool has);
};

#endif // GOKART_RACEGOKART_H
