#include "Hero.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Utils.h"
#include "GameFactory.h"

#include <iostream>
#include <vector>
#include <memory>
#include <ctime>      // voor srand(time(0))
#include <cstdlib>    // voor rand()

using namespace Game;

int main() {
    // Seed random generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Hero krijgt een random wapen
    std::shared_ptr<Character> hero =
        std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());

    // Spawn één random Enemy
    std::shared_ptr<Character> enemy = GameFactory::spawnRandomEnemy();

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

        // Hero kan ook healen (optioneel, 30% kans)
        if (rand() % 100 < 30) {
            std::dynamic_pointer_cast<Hero>(hero)->heal(5);
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
