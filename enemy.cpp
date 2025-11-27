#include "Enemy.h"
#include <iostream>

namespace Game {

Enemy::Enemy()
    : Character("Goblin", 40, Weapon("Claws", 5)) {}

Enemy::Enemy(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, weapon) {}

Enemy::Enemy(const Enemy& other)
    : Character(other) {}

Enemy::~Enemy() {}

void Enemy::attack(Character* target) {
    if (!target) return;

    int dmg = weapon.getDamage();
    std::cout << name << " valt " << target->getName()
              << " aan met " << weapon.getName()
              << " voor " << dmg << " schade!\n";

    target->takeDamage(dmg);
}

}
