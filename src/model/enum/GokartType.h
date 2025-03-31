#ifndef GOKART_TYPE_H
#define GOKART_TYPE_H

#include <string>

enum class GokartType {
    Small,
    Big,
    Race,
};

constexpr const char *toString(GokartType type) {
    switch (type) {
        case GokartType::Small:
            return "Small";
        case GokartType::Big:
            return "Big";
        case GokartType::Race:
            return "Race";
        default:
            return "Unknown";
    }
}

#endif // GOKART_TYPE_H