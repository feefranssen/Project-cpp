#include "Character.h"
#include "Utils.h" // template clamp

namespace Game {

Character::Character()
    : name("Unknown"), health(50), weapon("Fists", 3), level(1), isAlive(true) {}

Character::Character(const std::string& name, int health, const Weapon& weapon)
    : name(name), health(health), weapon(weapon), level(1), isAlive(true) {}

Character::Character(const Character& other)
    : name(other.name), health(other.health), weapon(other.weapon),
      level(other.level), isAlive(other.isAlive) {}

Character::~Character() {}

void Character::takeDamage(int amount) {
    health -= amount;
    health = Game::clamp(health, 0, 1000);
    if (health <= 0) isAlive = false;
}

// Friend operator
std::ostream& operator<<(std::ostream& os, const Character& c) {
    os << c.name << " (Health: " << c.health
       << ", Level: " << (int)c.level
       << ", Weapon: " << c.weapon << ")";
    return os;
}

}
