#include "Hero.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>

namespace Game {

Hero::Hero()    // Vraag 12 – default constructor
    : Hero("DefaultHero", 100, Weapon("Fists", 5)) {} // Vraag 17 – constructor forwarding

Hero::Hero(const std::string& name, int health, const Weapon& weapon)    // Vraag 13 – parameterized constructor
    : Character(name, health, weapon.getDamage()), weapon(weapon) {}


Hero::Hero(const Hero& other)   // Vraag 14 – copy constructor
    : Character(other), weapon(other.weapon) {}

Hero::~Hero() {} // Vraag 15 – destructor

bool Hero::dodge() {
    return rand() % 100 < 20; // 20% kans
}

void Hero::attack(Character& target) {  // Vraag 34 – modern call-by-reference
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

void Hero::takeDamage(int amount) {  // Vraag 5 – maintainability: duidelijke functie + consistente stijl
    if (dodge()) {
        std::cout << this->getName() << " dodged the attack!\n";
        return;
    }

    this->health -= amount; // Vraag 19 – useful usage of this
    if (this->health < 0) this->health = 0;
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
