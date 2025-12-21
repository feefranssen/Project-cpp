#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Weapon.h"

namespace Game {

class Hero; // forward declaration

class Enemy : public Character {
private:
    Weapon weapon;
    bool aggressive;    // Vraag 31 – useful bool

public:
    Enemy();
    Enemy(const std::string& name, int health, const Weapon& weapon);// Vraag 30 – const reference function parameter
    Enemy(const Enemy& other);
    virtual ~Enemy();

    virtual void attack(Character& target) override;

    Weapon getWeapon() const { return weapon; }

    bool isAggressive() const { return aggressive; }
    void applyAggression() { aggressive = true; }
    void consumeAggression() { aggressive = false; }

    void inspectTarget(const Character& c) const;
};

}

#endif
