#ifndef GOKART_GOKART_H
#define GOKART_GOKART_H

#include "../enum/GokartType.h"
#include <string>

class Gokart {
protected:
    static constexpr int DEFAULT_WHEEL_COUNT = 4;

    std::string serialNumber;
    int maxSpeed;
    GokartType type;
    int numberOfWheels = DEFAULT_WHEEL_COUNT;

    virtual ~Gokart() = default;


public:
    Gokart(std::string serial, int speed, GokartType type)
            : serialNumber(std::move(serial)), maxSpeed(speed), type(type) {}

    virtual void performMaintenance() = 0;

    [[nodiscard]] virtual std::string getSpecialFeatures() const = 0;

    [[nodiscard]] std::string getSerialNumber() const noexcept { return serialNumber; }

    [[nodiscard]] int getMaxSpeed() const noexcept { return maxSpeed; }

    [[nodiscard]] GokartType getType() const noexcept { return type; }

    void setMaxSpeed(int speed) {
        maxSpeed = speed;
    }
};

#endif // GOKART_GOKART_H