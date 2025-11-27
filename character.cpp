#include "Character.h"
#include "Utils.h" // for clamp template

namespace Game {

Character::Character()
    : name("Unknown"), health(50), weapon("Fists", 3) {}

Character::Character(const std::string& name, int health, const Weapon& weapon)
    : name(name), health(health), weapon(weapon) {}

Character::Character(const Character& other)
    : name(other.name), health(other.health), weapon(other.weapon) {}

Character::~Character() {}

void Character::takeDamage(int amount) {
    health -= amount;
    health = Game::clamp(health, 0, 1000); // using template clamp
}

// Friend operator
std::ostream& operator<<(std::ostream& os, const Character& c) {
    os << c.name << " (Health: " << c.health << ", Weapon: " << c.weapon << ")";
    return os;
}

}
