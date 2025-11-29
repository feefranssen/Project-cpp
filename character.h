#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Weapon.h"
#include <iostream>

namespace Game {

class Character {
protected:
    std::string name;
    int health;
    Weapon weapon;
    unsigned char level;  // geheugen-efficiënt level
    bool isAlive;         // status of character nog leeft

public:
    Character(); // default constructor
    Character(const std::string& name, int health, const Weapon& weapon); // parameterized constructor
    Character(const Character& other); // copy constructor
    virtual ~Character(); // virtual destructor

    // Inline getters
    const std::string& getName() const { return name; }
    int getHealth() const { return health; }
    const Weapon& getWeapon() const { return weapon; }
    bool getIsAlive() const { return isAlive; }
    unsigned char getLevel() const { return level; }

    // Setter using this
    void setHealth(int h) { this->health = h; }

    // Member function: default parameter
    virtual void takeDamage(int amount = 1);

    // Polymorphic function
    virtual void attack(Character* target) = 0;

    // Friend operator
    friend std::ostream& operator<<(std::ostream& os, const Character& c);
};

}

#endif // CHARACTER_H
