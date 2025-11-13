#include "hero.h"
#include "enemy.h"
#include <iostream>

int main() {
    Weapon sword("Sword", 10);
    Hero hero("Arthur", 50, sword);
    Enemy goblin("Goblin", 30);

    std::cout << hero.getName() << " encounters " << goblin.getName() << "!\n";

    hero.attack(goblin);
    goblin.attack(hero);

    std::cout << goblin.getName() << " health: " << goblin.getHealth() << "\n";
    std::cout << hero.getName() << " health: " << hero.getHealth() << "\n";
}
