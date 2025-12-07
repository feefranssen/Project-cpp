#include "Enemy.h"
#include "Utils.h"
#include <iostream>

namespace Game {

Enemy::Enemy()
    : Character("Goblin", 40, 5), weapon("Claws", 5), aggressive(false) {}

Enemy::Enemy(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, weapon.getDamage()), weapon(weapon), aggressive(false) {}

Enemy::Enemy(const Enemy& other)
    : Character(other), weapon(other.weapon), aggressive(other.aggressive) {}

Enemy::~Enemy() {}

void Enemy::attack(Character* target) {
    int damage = weapon.getDamage();

    // Aggression boost
    if (isAggressive()) {
        damage += 3;
        std::cout << "(Aggression Boost!) ";
        consumeAggression();
    }

    std::cout << name << " valt " << target->getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";

    target->takeDamage(damage);

    // Poison chance
    if (rand() % 100 < 25) {
        std::cout << name << " vergiftigt "
                  << target->getName() << "!\n";
        target->takeDamage(3);
    }

    // Summon chance
    if (rand() % 100 < 20) {
        std::cout << name << " roept een extra enemy op!!\n";

        if (Utils::enemyList) {
            Utils::enemyList->push_back(
                std::make_shared<Enemy>("Minion", 20, Weapon("Claws", 4))
                );
        }

    }


    // Become aggressive
    if (rand() % 100 < 30) {
        applyAggression();
        std::cout << name << " raakt agressief!\n";
    }

    // Level up chance
    if (rand() % 100 < 20) {
        levelUp();
        std::cout << name << " stijgt naar level "
                  << getLevel() << "!\n";
    }
}

}
