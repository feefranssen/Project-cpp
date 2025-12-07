#include "Hero.h"
#include "GameFactory.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>

using namespace Game;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Hero
    std::shared_ptr<Character> hero =
        std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());

    // Vector enemies
    std::vector<std::shared_ptr<Character>> enemies;
    enemies.push_back(GameFactory::spawnRandomEnemy());

    // Zet Utils::enemyList naar onze vector, zodat enemies zichzelf kunnen summon
    Utils::enemyList = &enemies;

    std::cout << hero->getName() << " ontmoet " << enemies[0]->getName() << "!\n\n";

    int round = 1;

    while (hero->getIsAlive() && !enemies.empty()) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Poison damage van hero
        std::dynamic_pointer_cast<Hero>(hero)->handlePoison();

        // Hero valt eerste enemy aan
        hero->attack(*enemies[0]);
        if (!enemies[0]->getIsAlive()) {
            std::cout << enemies[0]->getName() << " is verslagen!\n";
            enemies.erase(enemies.begin());
            if (enemies.empty()) break;
        }

        // Hero heal chance
        if (rand() % 100 < 30) {
            std::dynamic_pointer_cast<Hero>(hero)->heal(5);
        }

        // Elke enemy valt hero aan, inclusief eventuele nieuwe summons
        for (size_t i = 0; i < enemies.size(); ++i) {
            enemies[i]->attack(*hero);
        }

        if (!hero->getIsAlive()) {
            std::cout << hero->getName() << " is verslagen!\n";
            break;
        }

        // Status na ronde
        std::cout << "Status na ronde " << round << ":\n";
        std::cout << *hero << "\n";
        for (auto& e : enemies) std::cout << *e << "\n";
        std::cout << "\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << *hero << "\n";
    for (auto& e : enemies) std::cout << *e << "\n";

    return 0;
}
