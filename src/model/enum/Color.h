#ifndef GOKART_COLOR_H
#define GOKART_COLOR_H


enum class Color {
    Red,
    Green,
    Black,
    Yellow,
    Pink,
    Purple,
    Orange,
    White,
    Blue,
    Silver,
    Gold
};

// Utility functions
constexpr const char *toString(Color type) {
    switch (type) {
        case Color::Red:
            return "Red";
        case Color::Blue:
            return "Blue";
        case Color::Green:
            return "Green";
        case Color::Yellow:
            return "Yellow";
        case Color::Black:
            return "Black";
        case Color::Silver:
            return "Silver";
        case Color::Gold:
            return "Gold";
        case Color::White:
            return "White";
        case Color::Pink:
            return "Pink";
        case Color::Purple:
            return "Purple";
        case Color::Orange:
            return "Orange";

        default:
            return "Unknown";
    }
}


#endif //GOKART_COLOR_H
