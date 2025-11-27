#include "Character.h"
#include <iostream>

#include "Utils.h"

namespace Game {

Character::Character()
    : name("Unknown"), health(0), weapon("None", 0) {}

Character::Character(const std::string& name, int health, const Weapon& weapon)
    : name(name), health(health), weapon(weapon) {}

Character::Character(const Character& other)
    : name(other.name), health(other.health), weapon(other.weapon) {}

Character::~Character() {}

void Character::takeDamage(int amount) {
    health -= amount;
    // health altijd >= 0
    health = Game::clamp(health, 0, 1000); // max 1000 voor voorbeeld
}


void Character::attack(Character* target) {
    if (target == nullptr) return;

    std::cout << name << " attacks " << target->getName()
              << " with " << weapon.getName()
              << " for " << weapon.getDamage() << " damage.\n";

    target->takeDamage(weapon.getDamage());
}

}
