#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "weapon.h"
#include <iostream>

class Hero : public Character {
private:
    Weapon weapon;

public:
    Hero(const std::string& name, int health, const Weapon& weapon)
        : Character(name, health), weapon(weapon) {}

    void attack(Character& target) override {
        std::cout << name << " attacks " << target.getName()
        << " with " << weapon.getName()
        << " for " << weapon.getDamage() << " damage!\n";
        target.takeDamage(weapon.getDamage());
    }
};

#endif
