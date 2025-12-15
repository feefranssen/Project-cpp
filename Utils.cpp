#include "Utils.h"

namespace Game {
std::vector<std::shared_ptr<Character>>* Utils::enemyList = nullptr;

bool Utils::isLowHP(const Character& c, int threshold) {
    return c.getHealth() < threshold;

}

void Utils::createEnemyList() {
    enemyList = new std::vector<std::shared_ptr<Character>>();
}

void Utils::destroyEnemyList() {
    delete enemyList;
    enemyList = nullptr;
}


}
