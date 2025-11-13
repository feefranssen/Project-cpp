#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <iostream>
#include <random>

class Enemy : public Character {
public:
    Enemy(const std::string& name, int health)
        : Character(name, health) {}

    void attack(Character& target) override {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(3, 7);

        int damage = dist(gen);
        std::cout << name << " viciously bites " << target.getName()
                  << " for " << damage << " damage!\n";
        target.takeDamage(damage);
    }
};

#endif
