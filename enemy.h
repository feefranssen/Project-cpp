#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Weapon.h"
#include <string>

namespace Game {

class Enemy : public Character {
public:
    Enemy();
    Enemy(const std::string& name, int health, const Weapon& weapon);
    Enemy(const Enemy& other);
    virtual ~Enemy();

    virtual void attack(Character* target) override;
};

}

#endif
