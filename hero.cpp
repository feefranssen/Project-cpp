#include "Hero.h"
#include <iostream>

namespace Game {

Hero::Hero()
    : Character("DefaultHero", 100, Weapon("Fists", 3)) {}

Hero::Hero(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, weapon) {}

Hero::Hero(const Hero& other)
    : Character(other) {}

Hero::~Hero() {}

void Hero::attack(Character* target) {
    if (!target) return;

    int dmg = weapon.getDamage();
    std::cout << name << " valt " << target->getName()
              << " aan met " << weapon.getName()
              << " voor " << dmg << " schade!\n";

    target->takeDamage(dmg);
}

}
