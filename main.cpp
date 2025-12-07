#include "Hero.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Utils.h"
#include "GameFactory.h"

#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>

using namespace Game;

int main() {
    // Seed random generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Hero
    std::shared_ptr<Character> hero =
        std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());

    // Vector enemies
    std::vector<std::shared_ptr<Character>> enemies;
    enemies.push_back(GameFactory::spawnRandomEnemy());

    // Important: give Utils a pointer to enemies
    Utils::enemyList = &enemies;

    std::cout << hero->getName() << " ontmoet "
              << enemies[0]->getName() << "!\n\n";

    std::cout << "Start status:\n";
    std::cout << *hero << "\n";
    std::cout << *enemies[0] << "\n\n";

    int round = 1;

    // While hero alive AND at least one enemy alive
    while (hero->getIsAlive() && !enemies.empty()) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Hero attack first enemy for simplicity
        hero->attack(enemies[0].get());
        if (!enemies[0]->getIsAlive()) {
            std::cout << enemies[0]->getName() << " is verslagen!\n";
            enemies.erase(enemies.begin());
            if (enemies.empty()) break;
        }

        // Hero heal chance
        if (rand() % 100 < 30) {
            std::dynamic_pointer_cast<Hero>(hero)->heal(5);
        }

        // Every enemy attacks hero
        for (auto& e : enemies) {
            e->attack(hero.get());
        }

        if (!hero->getIsAlive()) {
            std::cout << hero->getName() << " is verslagen!\n";
            break;
        }

        std::cout << "Status na ronde " << round << ":\n";
        std::cout << *hero << "\n";
        for (auto& e : enemies)
            std::cout << *e << "\n";
        std::cout << "\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << *hero << "\n";
    for (auto& e : enemies)
        std::cout << *e << "\n";

    return 0;
}
