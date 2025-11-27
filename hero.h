#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Weapon.h"
#include <string>

namespace Game {

class Hero : public Character {
public:
    Hero();
    Hero(const std::string& name, int health, const Weapon& weapon);
    Hero(const Hero& other);
    virtual ~Hero();

    virtual void attack(Character* target) override;
};

}

#endif
