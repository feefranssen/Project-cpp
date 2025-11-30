#include "Enemy.h"
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

    if (isAggressive()) {
        damage += 3;
        std::cout << "(Aggression Boost!) ";
        consumeAggression();
    }

    std::cout << name << " valt " << target->getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";

    target->takeDamage(damage);

    // 30% kans om agressief te worden
    if (rand() % 100 < 30) {
        applyAggression();
        std::cout << name << " raakt agressief!\n";
    }

    // Optioneel: level omhoog bij aanval
    if (rand() % 100 < 20) {  // 20% kans
        levelUp();
        std::cout << name << " stijgt naar level " << getLevel() << "!\n";
    }
}

}
