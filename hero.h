#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Weapon.h"
#include <string>

namespace Game {

class Hero : public Character {
private:
    Weapon weapon;
    unsigned char baseDamage;
    bool dodge();

public:
    Hero();
    Hero(const std::string& name, int health, const Weapon& weapon);
    Hero(const Hero& other);
    virtual ~Hero();

    virtual void takeDamage(int amount) override;
    virtual void attack(Character* target) override;

    void setWeapon(const Weapon& weapon);   // this-> gebruik
    void heal(int amount = 5);              // default argument
};

}

#endif
