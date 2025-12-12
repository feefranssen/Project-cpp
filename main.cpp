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

    // Hero aanmaken
    std::shared_ptr<Character> hero =
        std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());

    // Vector van enemies
    std::vector<std::shared_ptr<Character>> enemies;
    enemies.push_back(GameFactory::spawnRandomEnemy());

    // Zet Utils::enemyList naar onze vector zodat enemies zichzelf kunnen summon
    Utils::enemyList = &enemies;

    std::cout << hero->getName() << " ontmoet " << enemies[0]->getName() << "!\n\n";

    int round = 1;

    while (hero->getIsAlive() && !enemies.empty()) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Poison schade van hero
        std::dynamic_pointer_cast<Hero>(hero)->handlePoison();

        // Hero valt eerste enemy aan
        hero->attack(*enemies[0]);
        if (!enemies[0]->getIsAlive()) {
            std::cout << enemies[0]->getName() << " is verslagen!\n";
            enemies.erase(enemies.begin());
            if (enemies.empty()) break;
        }

        // Hero heeft een kans om te healen
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

        if (rand() % 100 < 20) {
            Weapon found = GameFactory::getRandomHeroWeapon();
            std::shared_ptr<Hero> h = std::dynamic_pointer_cast<Hero>(hero);

            // Vergelijk damage van gevonden wapen met huidig wapen
            if (found.getDamage() > h->getWeapon().getDamage()) {
                std::cout << h->getName() << " vindt een beter wapen: "
                          << found.getName()
                          << " (Damage: " << found.getDamage() << ") en pakt het op!\n";
                h->setWeapon(found);
            }
        }

        // Status na ronde overzichtelijk printen
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
