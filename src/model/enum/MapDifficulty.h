#ifndef GOKART_MAPDIFFICULTY_H
#define GOKART_MAPDIFFICULTY_H


enum class MapDifficulty {
    Easy,
    Medium,
    Hard
};

constexpr const char *toString(MapDifficulty type) {
    switch (type) {
        case MapDifficulty::Easy:
            return "Easy";
        case MapDifficulty::Medium:
            return "Medium";
        case MapDifficulty::Hard:
            return "Hard";
        default:
            return "Unknown";
    }
}


#endif //GOKART_MAPDIFFICULTY_H
