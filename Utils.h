#ifndef UTILS_H
#define UTILS_H

#include "Character.h"

namespace Game {

class Utils {
public:
    static bool isLowHP(const Character& c, int threshold);

    // Template functie
    template<typename T>
    static T clamp(T value, T min, T max) {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }
};

} // namespace Game

#endif
