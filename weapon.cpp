#include "Weapon.h"

//  Constructor forwarding
Weapon::Weapon()
    : Weapon("Fists", 3)
{}

Weapon::Weapon(const std::string& name, int baseDamage)
    : name(name), baseDamage(baseDamage)
{}

Weapon::Weapon(const Weapon& other)
    : name(other.name), baseDamage(other.baseDamage)
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
