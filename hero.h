#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Weapon.h"
#include <string>

class Hero : public Character {
private:
    Weapon weapon;

public:
    Hero(); // default constructor
    Hero(const std::string& name, int health, const Weapon& weapon); // parameterized constructor
    Hero(const Hero& other); // copy constructor
    virtual ~Hero(); // destructor

    virtual void attack(Character& target) override; // polymorphic attack
};

#endif // HERO_H
