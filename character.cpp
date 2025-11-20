#include "character.h"

Character::Character(const std::string& name, int health)
    : name(name), health(health)
{}

Character::~Character() = default;

int Character::getHealth() const {
    return health;
}

const std::string& Character::getName() const {
    return name;
}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}
