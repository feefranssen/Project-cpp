#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "weapon.h"

class Hero : public Character {
private:
    Weapon weapon;

public:
    Hero(const std::string& name, int health, const Weapon& weapon);
    void attack(Character& target) override;
};

#endif // HERO_H
