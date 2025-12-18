#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Weapon.h"

namespace Game {

class Hero;

class Enemy : public Character {
private:
    Weapon weapon;
    bool aggressive;

public:
    Enemy();
    Enemy(const std::string& name, int health, const Weapon& weapon);
    Enemy(const Enemy& other);
    virtual ~Enemy();

    virtual void attack(Character& target) override;


    bool isAggressive() const { return aggressive; }
    void applyAggression() { aggressive = true; }
    void consumeAggression() { aggressive = false; }

    void inspectTarget(const Character& c) const;
};

}

#endif
