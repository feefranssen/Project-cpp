#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Weapon.h"
#include <string>

namespace Game {

class Hero : public Character {
private:
    Weapon weapon;
    bool dodge();
    int poisonCounter = 0; // poison voor 2 rondes

public:
    Hero();
    Hero(const std::string& name, int health, const Weapon& weapon);
    Hero(const Hero& other);
    virtual ~Hero();

    virtual void takeDamage(int amount) override;
    virtual void attack(Character& target) override;

    void setWeapon(const Weapon& weapon);
    Weapon getWeapon() const { return weapon; }

    void heal(int amount = 5);

    // Poison functies
    void handlePoison();
    bool isPoisoned() const { return poisonCounter > 0; }
    void setPoisonCounter(int rounds) { poisonCounter = rounds; }
};

}

#endif
