#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include <memory>
#include "Weapon.h"
#include "Character.h"
#include "Enemy.h"

namespace Game {

class GameFactory {
public:
    static Weapon getRandomHeroWeapon();
    static std::shared_ptr<Character> spawnRandomEnemy();
    static void describeEnemyType(const Enemy& e);

};

}

#endif
