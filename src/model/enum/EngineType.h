#ifndef GOKART_ENGINETYPE_H
#define GOKART_ENGINETYPE_H


enum class EngineType {
    Gasoline,
    Electric,
    Hybrid,
    Turbocharged,
};

constexpr const char *toString(EngineType type) {
    switch (type) {
        case EngineType::Gasoline:
            return "Gasoline";
        case EngineType::Electric:
            return "Electric";
        case EngineType::Hybrid:
            return "Hybrid";
        case EngineType::Turbocharged:
            return "Turbocharged";
        default:
            return "Unknown";
    }
}

#endif //GOKART_ENGINETYPE_H
