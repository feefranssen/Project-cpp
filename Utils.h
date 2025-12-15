#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <memory>
#include "Character.h"

namespace Game {

class Utils {
public:
    // Pointer naar de enemy lijst
    static std::vector<std::shared_ptr<Character>>* enemyList;

    static bool isLowHP(const Character& c, int threshold);

    static void createEnemyList();
    static void destroyEnemyList();

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
