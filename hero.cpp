#include "Hero.h"
#include <iostream>

namespace Game {

Hero::Hero()
    : Character("DefaultHero", 100, 10), weapon("Fists", 5) {}

Hero::Hero(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, weapon.getDamage()), weapon(weapon) {}

Hero::Hero(const Hero& other)
    : Character(other), weapon(other.weapon) {}

Hero::~Hero() {}

void Hero::heal(int amount) {
    std::cout << name << " healt zichzelf voor " << amount << " HP!\n";
    int newHP = health + amount;
    setHealth(newHP);
}

void Hero::setWeapon(const Weapon& weapon) {
    this->weapon = weapon;   // <-- nuttige this
}

void Hero::attack(Character* target) {
    int damage = weapon.getDamage();
    std::cout << name << " valt " << target->getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";
    target->takeDamage(damage);

    // Optioneel: level omhoog bij aanval
    if (rand() % 100 < 40) {  // 20% kans
        levelUp();
        std::cout << name << " stijgt naar level " << getLevel() << "!\n";
    }
}

}
