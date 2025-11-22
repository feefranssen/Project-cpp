#include "hero.h"
#include "enemy.h"
#include "weapon.h"
#include <iostream>
#include <vector>
#include <memory> // voor smart pointers

int main() {
    // Weapons
    Weapon sword("Sword", 10);
    Weapon claws("Claws", 8);

    // Characters via base class pointers (dynamic polymorphism)
    std::vector<std::shared_ptr<Character>> characters;

    characters.push_back(std::make_shared<Hero>("Arthur", 40, sword));
    characters.push_back(std::make_shared<Enemy>("Goblin", 30, claws));

    std::cout << characters[0]->getName() << " encounters "
              << characters[1]->getName() << "!\n\n";

    int round = 1;

    while (characters[0]->getHealth() > 0 && characters[1]->getHealth() > 0) {
        std::cout << "=== Ronde " << round << " ===\n";

        // Hero valt Enemy aan via base class pointer
        characters[0]->attack(*characters[1]);
        if (characters[1]->getHealth() <= 0) {
            std::cout << characters[1]->getName() << " is verslagen!\n";
            break;
        }

        // Enemy valt Hero aan via base class pointer
        characters[1]->attack(*characters[0]);
        if (characters[0]->getHealth() <= 0) {
            std::cout << characters[0]->getName() << " is verslagen!\n";
            break;
        }

        std::cout << characters[0]->getName() << " health: " << characters[0]->getHealth() << "\n";
        std::cout << characters[1]->getName() << " health: " << characters[1]->getHealth() << "\n\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";
    std::cout << characters[0]->getName() << " health: " << characters[0]->getHealth() << "\n";
    std::cout << characters[1]->getName() << " health: " << characters[1]->getHealth() << "\n";

    return 0;
}
