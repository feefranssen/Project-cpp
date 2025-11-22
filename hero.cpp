#include "Hero.h"
#include <iostream>

//  Constructor forwarding: default → parameterized
Hero::Hero()
    : Hero("DefaultHero", 100, Weapon())
{}

Hero::Hero(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, 10), weapon(weapon)
{}

Hero::Hero(const Hero& other)
    : Character(other.name, other.health, 10), weapon(other.weapon)
{}

Hero::~Hero() {}

void Hero::attack(Character& target) {
    int damage = weapon.getDamage();
    std::cout << name << " valt " << target.getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";
    target.takeDamage(damage);
}

