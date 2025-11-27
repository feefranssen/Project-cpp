#include "Hero.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace Game;

int main() {
    Weapon sword("Sword", 10);
    Weapon claws("Claws", 8);

    std::vector<std::shared_ptr<Character>> characters;
    characters.push_back(std::make_shared<Hero>("Arthur", 40, sword));
    characters.push_back(std::make_shared<Enemy>("Goblin", 30, claws));

    std::cout << characters[0]->getName() << " ontmoet "
              << characters[1]->getName() << "!\n\n";

    std::cout << "Start status:\n";
    std::cout << *characters[0] << "\n";
    std::cout << *characters[1] << "\n\n";

    int round = 1;

    while (characters[0]->getHealth() > 0 && characters[1]->getHealth() > 0) {
        std::cout << "=== Ronde " << round << " ===\n";

        characters[0]->attack(characters[1].get());
        if (characters[1]->getHealth() <= 0) {
            std::cout << characters[1]->getName() << " is verslagen!\n";
            break;
        }

        characters[1]->attack(characters[0].get());
        if (characters[0]->getHealth() <= 0) {
            std::cout << characters[0]->getName() << " is verslagen!\n";
            break;
        }

        std::cout << "Status na ronde " << round << ":\n";
        std::cout << *characters[0] << "\n";
        std::cout << *characters[1] << "\n\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << *characters[0] << "\n";
    std::cout << *characters[1] << "\n";

    return 0;
}
