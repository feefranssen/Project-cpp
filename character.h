// Vraag 6 – separate header files per class
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

namespace Game {

class Character {
protected:
    std::string name; //Vraag 4 – Correct protections
    int health;
    unsigned char baseDamage;   // Vraag 28 – memory efficient type
    unsigned char level;    // Vraag 28 – memory efficient type

public:
    Character();
    Character(const std::string& name, int health, unsigned char baseDamage);   // Vraag 30 – const reference function parameter

    Character(const Character& other);
    virtual ~Character();

    virtual void attack(Character& target) = 0; // Vraag 34 – modern call-by-reference

    int getHealth() const { return health; }    // Vraag 23 – getter
    const std::string& getName() const { return name; }
    int getLevel() const { return level; }
    bool getIsAlive() const { return health > 0; }  // Vraag 24 – inline function       // Vraag 31 – useful bool

    void setHealth(int h) { health = h; }   // Vraag 23 – setter
    void levelUp() { level++; }

    virtual void takeDamage(int amount);
};

std::ostream& operator<<(std::ostream& os, const Character& c);

}

#endif
