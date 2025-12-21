#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Weapon.h"
#include <string>

namespace Game {

class Hero : public Character {
private:
    Weapon weapon;
    bool dodge();   // Vraag 31 – useful bool
    int poisonCounter = 0; // Vraag 22 – useful member variable

public:
    Hero();
    Hero(const std::string& name, int health, const Weapon& weapon);// Vraag 30 – const reference function parameter
    Hero(const Hero& other);
    virtual ~Hero();

    virtual void takeDamage(int amount) override;
    virtual void attack(Character& target) override;

    void setWeapon(const Weapon& weapon);
    Weapon getWeapon() const { return weapon; }

    //Vraag 21 – default values in function definition
    void heal(int amount = 5);  // Vraag 20 – useful member function

    // Poison functies
    void handlePoison();
    bool isPoisoned() const { return poisonCounter > 0; }       // Vraag 31 – useful bool
    void setPoisonCounter(int rounds) { poisonCounter = rounds; }
};

}

#endif
