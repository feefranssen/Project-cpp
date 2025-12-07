#include "Hero.h"
#include "Utils.h"
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

void Hero::attack(Character& target) {
    int damage = weapon.getDamage();
    std::cout << name << " valt " << target.getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";
    target.takeDamage(damage);

    if (rand() % 100 < 40) {
        levelUp();
        std::cout << name << " stijgt naar level " << getLevel() << "!\n";
    }
}

void Hero::takeDamage(int amount) {
    if (dodge()) {
        std::cout << getName() << " dodged the attack!\n";
        return;
    }

    health -= amount;
    if (health < 0) health = 0;
}

void Hero::heal(int amount) {
    int newHP = health + amount;
    newHP = Utils::clamp<int>(newHP, 0, 100);
    setHealth(newHP);
    std::cout << name << " healt zichzelf voor " << amount << " HP, HP nu: " << health << "\n";
}

void Hero::handlePoison() {
    if (poisonCounter > 0) {
        int poisonDamage = 3;
        health -= poisonDamage;
        if (health < 0) health = 0;
        std::cout << getName() << " lijdt " << poisonDamage
                  << " poison schade, HP nu: " << health << "\n";
        poisonCounter--;
    }
}

void Hero::setWeapon(const Weapon& weapon) {
    this->weapon = weapon;
}

}
