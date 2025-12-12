#include "Enemy.h"
#include "Hero.h"
#include "Utils.h"
#include "GameFactory.h"
#include <iostream>

namespace Game {

Enemy::Enemy()
    : Character("Goblin", 40, 5), weapon("Claws", 5), aggressive(false) {}

Enemy::Enemy(const std::string& name, int health, const Weapon& weapon)
    : Character(name, health, weapon.getDamage()), weapon(weapon), aggressive(false) {}

Enemy::Enemy(const Enemy& other)
    : Character(other), weapon(other.weapon), aggressive(other.aggressive) {}

Enemy::~Enemy() {}

void Enemy::attack(Character& target) {
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
        std::cout << name << " vergiftigt " << hero->getName() << " voor 2 rondes!\n";
    }

    if (rand() % 100 < 30) {
        applyAggression();
        std::cout << name << " raakt agressief!\n";
    }

    if (rand() % 100 < 20) {
        levelUp();
        std::cout << name << " stijgt naar level " << getLevel() << "!\n";
    }

    // Summon alleen als max 2 enemies nog niet bereikt
    if (rand() % 100 < 20 && Utils::enemyList != nullptr && Utils::enemyList->size() < 2) {
        std::shared_ptr<Character> newEnemy = GameFactory::spawnRandomEnemy();
        Utils::enemyList->push_back(newEnemy);

        // Inspecteer hero omdat we een belangrijke actie uitvoeren
        inspectTarget(*hero);

        std::cout << name << " roept een extra enemy op: "
                  << newEnemy->getName() << "!\n";
    }
}

void Enemy::inspectTarget(const Character& c) const {
    // Enkel printen als er echt iets gebeurt
    std::cout << name << " bekijkt " << c.getName()
              << " (HP: " << c.getHealth() << ", Level: " << c.getLevel() << ")\n";
}

}
