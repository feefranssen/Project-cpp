#include "hero.h"
#include <iostream>

Hero::Hero(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health), weapon(weapon)
{}

void Hero::attack(Character& target) {
    std::cout << name << " attacks " << target.getName()
    << " with " << weapon.getName()
    << " for " << weapon.getDamage() << " damage!\n";
    target.takeDamage(weapon.getDamage());
}
