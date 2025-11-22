#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int baseDamage;

public:
    Character(); // default constructor
    Character(const std::string& name, int health, int baseDamage); // parameterized constructor
    virtual ~Character(); // virtual destructor

    virtual void attack(Character& target) = 0; // pure virtual function

    // Inline getters
    int getHealth() const { return health; }
    const std::string& getName() const { return name; }

    // Setter met gebruik van 'this'
    Character* setHealth(int h) { this->health = h; return this; }

    // Member function
    virtual void takeDamage(int amount);
};

#endif // CHARACTER_H
