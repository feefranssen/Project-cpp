#include "Hero.h"
#include "GameFactory.h"
#include "Utils.h"

#include <iostream>
#include <memory>
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

    // Enemy list dynamisch aanmaken
    Utils::createEnemyList();
    Utils::enemyList->push_back(GameFactory::spawnRandomEnemy());

    std::cout << hero->getName()
              << " ontmoet "
              << Utils::enemyList->at(0)->getName()
              << "!\n\n";

    int round = 1;

    while (hero->getIsAlive() && !Utils::enemyList->empty()) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Poison schade van hero
        std::dynamic_pointer_cast<Hero>(hero)->handlePoison();

        // Hero valt eerste enemy aan
        hero->attack(*Utils::enemyList->at(0));
        if (!Utils::enemyList->at(0)->getIsAlive()) {
            std::cout << Utils::enemyList->at(0)->getName()
            << " is verslagen!\n";
            Utils::enemyList->erase(Utils::enemyList->begin());
            if (Utils::enemyList->empty()) break;
        }

        // Heal kans
        if (rand() % 100 < 30) {
            std::dynamic_pointer_cast<Hero>(hero)->heal(5);
        }

        // Enemies vallen aan
        for (size_t i = 0; i < Utils::enemyList->size(); ++i) {
            Utils::enemyList->at(i)->attack(*hero);
        }

        if (!hero->getIsAlive()) {
            std::cout << hero->getName() << " is verslagen!\n";
            break;
        }

        // Weapon drop
        if (rand() % 100 < 20) {
            Weapon found = GameFactory::getRandomHeroWeapon();
            auto h = std::dynamic_pointer_cast<Hero>(hero);

            if (found.getDamage() > h->getWeapon().getDamage()) {
                std::cout << h->getName()
                << " vindt een beter wapen: "
                << found.getName()
                << " (Damage: " << found.getDamage() << ")\n";
                h->setWeapon(found);
            }
        }

        // Status
        std::cout << "Status na ronde " << round << ":\n";
        std::cout << *hero << "\n";
        for (auto& e : *Utils::enemyList) std::cout << *e << "\n";
        std::cout << "\n";

        round++;
    }

    auto saveGame = [](const Hero& hero) {
        try {
            std::ofstream outFile("save.txt");

            if (!outFile.is_open()) {
                throw std::runtime_error("save.txt kon niet geopend worden");
            }

            // Hero stats
            outFile << "Hero " << hero.getName() << " "
                    << hero.getHealth() << " "
                    << hero.getLevel() << " "
                    << hero.getWeapon().getName() << " "
                    << hero.getWeapon().getBaseDamage() << "\n";

            // Enemies stats
            for (auto& e : *Utils::enemyList) {
                outFile << "Enemy " << e->getName() << " "
                        << e->getHealth() << " "
                        << e->getLevel() << "\n";
            }

            outFile.close();
            std::cout << "Game opgeslagen in save.txt\n";
        }
        catch (const std::exception& ex) {
            std::cerr << "Save error: " << ex.what() << "\n";
        }
    };


    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << *hero << "\n";
    for (auto& e : *Utils::enemyList) std::cout << *e << "\n";

    std::thread saveThread(
        saveGame,
        *std::dynamic_pointer_cast<Hero>(hero)
        );

    saveThread.join();


    // Dynamisch geheugen opruimen
    Utils::destroyEnemyList();

    return 0;
}
