#include "Weapon.h"
#include <cstdlib>

namespace Game {

Weapon::Weapon() : Weapon("Fists", 3) {}// Vraag 12 – default constructor

Weapon::Weapon(const std::string& name, unsigned char baseDamage)// Vraag 35 – string usage
    : name(name), baseDamage(baseDamage) {}

Weapon::Weapon(const Weapon& other)     // Vraag 14 – copy constructor
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

int Weapon::compare(const Weapon& other) const {
    if (baseDamage > other.baseDamage) return 1;
    if (baseDamage < other.baseDamage) return -1;
    return 0;
}

// operator<<
std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << w.name << " (Damage: " << static_cast<int>(w.baseDamage) << ")";
    return os;
}

// operator>
bool operator>(const Weapon& lhs, const Weapon& rhs) {
    return lhs.baseDamage > rhs.baseDamage;
}

}
