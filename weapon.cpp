#include "weapon.h"

Weapon::Weapon(const std::string& name, int baseDamage)
    : name(name), baseDamage(baseDamage)
{}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(baseDamage - 2, baseDamage + 2);
    return dist(gen);
}
