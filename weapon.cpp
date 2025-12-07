#include "Weapon.h"
#include <cstdlib>

namespace Game {

Weapon::Weapon() : Weapon("Fists", 3) {}
Weapon::Weapon(const std::string& name, unsigned char baseDamage)
    : name(name), baseDamage(baseDamage) {}
Weapon::Weapon(const Weapon& other)
    : name(other.name), baseDamage(other.baseDamage) {}
Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        name = other.name;
        baseDamage = other.baseDamage;
    }
    return *this;
}

std::string Weapon::getName() const { return name; }
int Weapon::getDamage() const { return static_cast<int>(baseDamage) + (rand() % 5 - 2); }

std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << w.name << " (Damage: " << static_cast<int>(w.baseDamage) << ")";
    return os;
}

}
