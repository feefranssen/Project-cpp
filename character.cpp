#include "Character.h"

namespace Game {

Character::Character() : Character("Default", 50, 5) {}

Character::Character(const std::string& name, int health, unsigned char baseDamage)  // Vraag 16 – member initialization list
    : name(name), health(health), baseDamage(baseDamage), level(1) {}

Character::Character(const Character& other)
    : name(other.name), health(other.health), baseDamage(other.baseDamage), level(other.level) {}

Character::~Character() {}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

std::ostream& operator<<(std::ostream& os, const Character& c) {
    os << c.getName() << " (Level: " << c.getLevel() << ", HP: " << c.getHealth() << ")";
    return os;
}

}
