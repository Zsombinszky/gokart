#ifndef GOKART_GOKART_H
#define GOKART_GOKART_H

#include "../enum/GokartType.h"
#include <string>

class Gokart {
protected:
    std::string serialNumber;
    int maxSpeed;
    GokartType type;
    int numberOfWheels = 4;

public:
    Gokart(std::string serial, int speed, GokartType type)
            : serialNumber(std::move(serial)), maxSpeed(speed), type(type) {}

    virtual ~Gokart() = default;

    virtual void performMaintenance() = 0;

    [[nodiscard]] virtual std::string getSpecialFeatures() const = 0;

    // Common methods
    [[nodiscard]] std::string getSerialNumber() const { return serialNumber; }

    [[nodiscard]] int getMaxSpeed() const { return maxSpeed; }

    [[nodiscard]] GokartType getType() const { return type; }
};

#endif // GOKART_GOKART_H