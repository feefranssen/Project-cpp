#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Weapon.h"

namespace Game {

class Character {
protected:
    std::string name;
    int health;
    Weapon weapon;

public:
    // Default constructor
    Character();

    // Parameterized constructor
    Character(const std::string& name, int health, const Weapon& weapon);

    // Copy constructor
    Character(const Character& other);

    // Virtual destructor
    virtual ~Character();

    // Getters
    inline const std::string& getName() const { return name; }
    inline int getHealth() const { return health; }
    inline const Weapon& getWeapon() const { return weapon; }

    // Setters (example use of 'this')
    inline void setHealth(int h) { this->health = h; }

    // Default parameter added here (1 damage if nothing provided)
    virtual void takeDamage(int amount = 1);

    // Polymorphic function
    virtual void attack(Character* target);
};

}

#endif
