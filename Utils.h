#ifndef UTILS_H
#define UTILS_H

#include "Character.h"
#include <iostream>

namespace Game {

class Utils {
public:
    static bool isLowHP(const Character& c, int threshold);

    template<typename T>
    static T clamp(T value, T min, T max) {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }

    static void printCharacterInfo(const Character& c) {
        std::cout << c.getName() << " (HP: " << c.getHealth()
        << ", Level: " << c.getLevel() << ")\n";
    }
};

}

#endif
