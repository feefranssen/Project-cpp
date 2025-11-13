#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;

public:
    Character(const std::string& name, int health)
        : name(name), health(health) {}

    virtual ~Character() {}

    virtual void attack(Character& target) = 0;

    int getHealth() const { return health; }

    std::string getName() const { return name; }

    virtual void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }
};

#endif
