#include "Enemy.h"
#include "Hero.h"
#include <iostream>
#include <cstdlib>

namespace Game {

Enemy::Enemy() : Character("Goblin", 40, 5), weapon("Claws", 5), aggressive(false) {}

Enemy::Enemy(const std::string& name, int health, const Weapon& weapon)      // Vraag 13 – parameterized constructor
    : Character(name, health, weapon.getDamage()), weapon(weapon), aggressive(false) {}

Enemy::Enemy(const Enemy& other)
    : Character(other), weapon(other.weapon), aggressive(other.aggressive) {}

Enemy::~Enemy() {}  // Vraag 15 – destructor

void Enemy::attack(Character& target) { // Vraag 18 – dynamic polymorphism via virtual function
    const Weapon& weaponRef = weapon; // Vraag 29 – const reference variable
    int damage = weapon.getDamage();

    if (isAggressive()) {
        damage += 3;
        consumeAggression();
        std::cout << "(Aggression Boost!) ";
    }

    std::cout << name << " valt " << target.getName()
              << " aan met " << weapon.getName()
              << " voor " << damage << " schade!\n";

    target.takeDamage(damage);

    Hero* hero = dynamic_cast<Hero*>(&target);
    if (hero && !hero->isPoisoned() && rand() % 100 < 25) {
        hero->setPoisonCounter(2);
        std::cout << name << " vergiftigt " << hero->getName() << "!\n";
    }
}

void Enemy::inspectTarget(const Character& c) const {
    std::cout << name << " inspecteert " << c.getName()
    << " (HP: " << c.getHealth() << ")\n";
}

}
