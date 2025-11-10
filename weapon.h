#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <random>

class Weapon {
private:
    std::string name;
    int baseDamage;

public:
    Weapon(const std::string& name, int baseDamage)
        : name(name), baseDamage(baseDamage) {}

    std::string getName() const { return name; }

    int getDamage() const {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(baseDamage - 2, baseDamage + 2);
        return dist(gen);
    }
};

#endif
