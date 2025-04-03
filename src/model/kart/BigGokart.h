#ifndef GOKART_BIGGOKART_H
#define GOKART_BIGGOKART_H

#include "Gokart.h"
#include "../enum/EngineType.h"

class BigGokart : public Gokart {
protected:
    static constexpr int BASE_BIGGOKART_SPEED = 20;
    static constexpr int BASE_BIGGOKART_POWER = 30;
    int _enginePower;
    bool _hasRollCage;
    bool _hasSportMode;
    EngineType _engineType;

public:
    explicit BigGokart(std::string serial, int speed = BASE_BIGGOKART_SPEED, int power = BASE_BIGGOKART_POWER, bool sportMode = true,
                       EngineType engine = EngineType::Gasoline)
            : Gokart(std::move(serial), speed, GokartType::Big),
              _enginePower(power), _hasSportMode(sportMode), _engineType(engine), _hasRollCage(true) {}

    void performMaintenance() override;

    [[nodiscard]] std::string getSpecialFeatures() const override;

    [[nodiscard]] bool hasRollCage() const noexcept;

    [[nodiscard]] bool hasSportMode() const noexcept;

    [[nodiscard]] EngineType getEngineType() const noexcept;

    [[nodiscard]] int getEnginePower() const;

    void setRollCage(bool hasRollCage);

    void setEnginePower(int enginePower);

    void setSportMode(bool hasSportMode);

    void setEngineType(EngineType engineType);
};

#endif // GOKART_BIGGOKART_H
