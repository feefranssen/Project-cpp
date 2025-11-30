#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

namespace Game {

class Character {
protected:
    std::string name;
    int health;
    int baseDamage;
    int level;   // level toegevoegd

public:
    Character(); // default constructor
    Character(const std::string& name, int health, int baseDamage); // parameterized constructor
    Character(const Character& other); // copy constructor
    virtual ~Character();

    virtual void attack(Character* target) = 0;

    // Getters
    int getHealth() const { return health; }
    const std::string& getName() const { return name; }
    int getLevel() const { return level; }  // getter level
    bool getIsAlive() const { return health > 0; }

    // Setters
    void setHealth(int h) { this->health = h; }

    // Level up
    void levelUp() { level++; }

    virtual void takeDamage(int amount);
};

std::ostream& operator<<(std::ostream& os, const Character& c);

}

#endif
