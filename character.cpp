#include "Character.h"

Character::Character()
    : name("Default"), health(50), baseDamage(5)
{}

Character::Character(const std::string& name, int health, int baseDamage)
    : name(name), health(health), baseDamage(baseDamage)
{}

Character::~Character() {}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}
