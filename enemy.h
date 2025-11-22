#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Weapon.h"
#include <string>

class Enemy : public Character {
private:
    Weapon weapon;

public:
    Enemy(); // default constructor
    Enemy(const std::string& name, int health, const Weapon& weapon); // parameterized constructor
    Enemy(const Enemy& other); // copy constructor
    virtual ~Enemy(); // destructor

    virtual void attack(Character& target) override; // polymorphic attack
};

#endif // ENEMY_H
