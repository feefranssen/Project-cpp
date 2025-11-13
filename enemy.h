#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
public:
    Enemy(const std::string& name, int health);
    void attack(Character& target) override;
};

#endif // ENEMY_H
