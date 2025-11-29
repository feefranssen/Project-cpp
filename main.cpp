#include "Hero.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <memory>
#include <random>

using namespace Game;

// Functie om Hero een random wapen te geven
Weapon getRandomHeroWeapon() {
    static std::vector<Weapon> heroWeapons = {
        Weapon("Sword", 10),
        Weapon("Axe", 12),
        Weapon("Dagger", 8)
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, heroWeapons.size() - 1);

    return heroWeapons[dist(gen)];
}

// Functie om een random Enemy-type te spawnen (alleen Claws als wapen)
std::shared_ptr<Character> spawnRandomEnemy() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    int choice = dist(gen);
    switch(choice) {
    case 0:
        return std::make_shared<Enemy>("Goblin", 30, Weapon("Claws", 10));
    case 1:
        return std::make_shared<Enemy>("Orc", 50, Weapon("Claws", 7));
    case 2:
        return std::make_shared<Enemy>("Troll", 80, Weapon("Claws", 5));
    default:
        return std::make_shared<Enemy>("Goblin", 30, Weapon("Claws", 10));
    }
}

int main() {
    // Hero krijgt een random wapen
    std::shared_ptr<Character> hero = std::make_shared<Hero>("Arthur", 40, getRandomHeroWeapon());

    // Spawn één random Enemy
    std::shared_ptr<Character> enemy = spawnRandomEnemy();

    std::vector<std::shared_ptr<Character>> characters = {hero, enemy};

    std::cout << hero->getName() << " ontmoet " << enemy->getName() << "!\n\n";

    std::cout << "Start status:\n";
    std::cout << *hero << "\n";
    std::cout << *enemy << "\n\n";

    int round = 1;

    while (hero->getIsAlive() && enemy->getIsAlive()) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Hero valt Enemy aan
        hero->attack(enemy.get());
        if (!enemy->getIsAlive()) {
            std::cout << enemy->getName() << " is verslagen!\n";
            break;
        }

        // Enemy valt Hero aan
        enemy->attack(hero.get());
        if (!hero->getIsAlive()) {
            std::cout << hero->getName() << " is verslagen!\n";
            break;
        }

        std::cout << "Status na ronde " << round << ":\n";
        std::cout << *hero << "\n";
        std::cout << *enemy << "\n\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << *hero << "\n";
    std::cout << *enemy << "\n";

    return 0;
}
