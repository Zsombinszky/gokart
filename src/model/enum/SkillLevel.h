#ifndef GOKART_SKILLLEVEL_H
#define GOKART_SKILLLEVEL_H


enum class SkillLevel {
    Beginner,
    Intermediate,
    Advanced,
    Pro
};

constexpr const char *toString(SkillLevel type) {
    switch (type) {
        case SkillLevel::Beginner:
            return "Beginner";
        case SkillLevel::Intermediate:
            return "Intermediate";
        case SkillLevel::Advanced:
            return "Advanced";
        case SkillLevel::Pro:
            return "Pro";
        default:
            return "Unknown";
    }
}


#endif //GOKART_SKILLLEVEL_H
