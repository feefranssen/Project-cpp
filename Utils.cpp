#include "Utils.h"

namespace Game {
std::vector<std::shared_ptr<Character>>* Utils::enemyList = nullptr;

bool Utils::isLowHP(const Character& c, int threshold) {
    return c.getHealth() < threshold;
}

}
