#include "Utils.h"
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

bool Hero::dodge() {
    return rand() % 100 < 20; // 20% kans
}

void Hero::attack(Character* target) {
    int damage = weapon.getDamage();
    std::cout << name << " valt " << target->getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";
    target->takeDamage(damage);

    // Level up chance
    if (rand() % 100 < 40) {
        levelUp();
        std::cout << name << " stijgt naar level "
                  << getLevel() << "!\n";
    }
}

void Hero::takeDamage(int amount) {
    if (dodge()) {
        std::cout << getName() << " dodged the attack!\n";
        return;
    }
    Character::takeDamage(amount);
}


void Hero::heal(int amount) {
    std::cout << name << " healt zichzelf voor " << amount << " HP!\n";

    int newHP = health + amount;

    // template-functie gebruiken
    newHP = Utils::clamp<int>(newHP, 0, 100); // <-- <int> is belangrijk voor templates

    setHealth(newHP);
}



void Hero::setWeapon(const Weapon& weapon) {
    this->weapon = weapon;
}

}
