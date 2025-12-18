#include "Hero.h"
#include "Enemy.h"
#include "GameFactory.h"

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <thread>

using namespace Game;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Hero aanmaken
    std::shared_ptr<Character> hero =
        std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());

    // Lokale enemy list
    std::vector<std::shared_ptr<Character>> enemies;
    enemies.push_back(GameFactory::spawnRandomEnemy());

    int round = 1;

    while (hero->getIsAlive() && !enemies.empty()) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Poison schade van hero
        std::dynamic_pointer_cast<Hero>(hero)->handlePoison();

        // Hero valt eerste enemy aan
        hero->attack(*enemies.front());
        if (!enemies.front()->getIsAlive()) {
            std::cout << enemies.front()->getName() << " is verslagen!\n";
            enemies.erase(enemies.begin());
            continue;
        }

        // Enemies vallen hero aan
        for (size_t i = 0; i < enemies.size(); ++i) {
            auto enemy = std::dynamic_pointer_cast<Enemy>(enemies[i]);
            enemy->attack(*hero);

            // Spawn extra enemy indien nodig
            if (rand() % 100 < 20 && enemies.size() < 2) {
                auto newEnemy = GameFactory::spawnRandomEnemy();
                enemies.push_back(newEnemy);
                std::cout << enemy->getName() << " roept een extra enemy op: "
                          << newEnemy->getName() << "!\n";
            }
        }

        // Heal kans voor hero
        if (rand() % 100 < 30) {
            std::dynamic_pointer_cast<Hero>(hero)->heal(5);
        }

        // Status na ronde
        std::cout << "\nStatus na ronde " << round << ":\n";
        std::cout << *hero << "\n";
        for (auto& e : enemies) std::cout << *e << "\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << *hero << "\n";
    for (auto& e : enemies) std::cout << *e << "\n";

    // Game save via thread
    auto saveGame = [&](const Hero& hero) {
        std::ofstream out("save.txt");
        if (!out) return;

        out << "Hero " << hero.getName() << " "
            << hero.getHealth() << " "
            << hero.getLevel() << "\n";

        for (auto& e : enemies) {
            out << "Enemy " << e->getName()
            << " " << e->getHealth()
            << " " << e->getLevel() << "\n";
        }
        std::cout << "Game opgeslagen in save.txt\n";
    };

    std::thread saveThread(saveGame, *std::dynamic_pointer_cast<Hero>(hero));
    saveThread.join();

    return 0;
}
