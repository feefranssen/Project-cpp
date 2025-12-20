#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

namespace Game {

class Character {
protected:
    std::string name;
    int health;
    unsigned char baseDamage;
    unsigned char level;

public:
    Character();
    Character(const std::string& name, int health, unsigned char baseDamage);
    Character(const Character& other);
    virtual ~Character();

    virtual void attack(Character& target) = 0;

    int getHealth() const { return health; }
    const std::string& getName() const { return name; }
    int getLevel() const { return level; }
    bool getIsAlive() const { return health > 0; }

    void setHealth(int h) { health = h; }
    void levelUp() { level++; }

    virtual void takeDamage(int amount);
};

std::ostream& operator<<(std::ostream& os, const Character& c);

}

#endif
