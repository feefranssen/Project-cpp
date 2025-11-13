#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;

public:
    Character(const std::string& name, int health);
    virtual ~Character();

    virtual void attack(Character& target) = 0;

    int getHealth() const;
    const std::string& getName() const;

    virtual void takeDamage(int amount);
};

#endif // CHARACTER_H
