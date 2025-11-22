#include "Enemy.h"
#include <iostream>

//  Constructor forwarding: default → parameterized
Enemy::Enemy()
    : Enemy("Goblin", 40, Weapon("Claws", 5))
{}

Enemy::Enemy(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, weapon.getDamage()), weapon(weapon)
{}

Enemy::Enemy(const Enemy& other)
    : Character(other.name, other.health, other.weapon.getDamage()), weapon(other.weapon)
{}

Enemy::~Enemy() {}

void Enemy::attack(Character& target) {
    int damage = weapon.getDamage();
    std::cout << name << " valt " << target.getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";
    target.takeDamage(damage);
}
