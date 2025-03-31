#ifndef GOKART_RACEGOKART_H
#define GOKART_RACEGOKART_H

#include "BigGokart.h"

class RaceGokart final : public BigGokart {
private:
    bool _hasTurboBoost;
    bool _hasOvertakeSign;

public:
    explicit RaceGokart(std::string serial, int speed = 100, int power = 25, bool sportMode = true,
                        EngineType engine = EngineType::Gasoline, bool turboBoost = true, bool overtakeSign = true);

    void performMaintenance() override;

    [[nodiscard]] std::string getSpecialFeatures() const override;

    [[nodiscard]] bool hasTurboBoost() const;

    [[nodiscard]] bool hasOvertakeSign() const;

    void setTurboBoost(bool has);

    void setOvertakeSign(bool has);
};

#endif // GOKART_RACEGOKART_H
