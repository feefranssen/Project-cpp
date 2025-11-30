#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Weapon.h"
#include <string>

namespace Game {

class Enemy : public Character {
private:
    Weapon weapon;
    bool aggressive;  // voor Aggression mechanic

public:
    Enemy();
    Enemy(const std::string& name, int health, const Weapon& weapon);
    Enemy(const Enemy& other);
    virtual ~Enemy();

    virtual void attack(Character* target) override;

    // Aggression functies
    bool isAggressive() const { return aggressive; }
    void applyAggression() { aggressive = true; }
    void consumeAggression() { aggressive = false; }
};

}

#endif
