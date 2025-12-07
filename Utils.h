#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <memory>

namespace Game {

// forward declaration
class Character;

class Utils {
public:
    // Ptr naar enemy list in main
    static std::vector<std::shared_ptr<Character>>* enemyList;

    // Template blijft gewoon bruisend hetzelfde
    template<typename T>
    static T clamp(T value, T min, T max) {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }
};

}

#endif
