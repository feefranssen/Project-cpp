#include "GameFactory.h"
#include <random>
#include <vector>
#include <iostream>

using namespace Game;

Weapon GameFactory::getRandomHeroWeapon() {
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

std::shared_ptr<Character> GameFactory::spawnRandomEnemy() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    switch (dist(gen)) {
    case 0:
        return std::make_shared<Enemy>("Goblin", 30, Weapon("Claws", 10));
    case 1:
        return std::make_shared<Enemy>("Orc", 40, Weapon("Claws", 6));
    case 2:
        return std::make_shared<Enemy>("Troll", 50, Weapon("Claws", 4));
    default:
        return std::make_shared<Enemy>("Goblin", 30, Weapon("Claws", 10));
    }
}

// Definieer describeEnemyType **buiten** spawnRandomEnemy
void GameFactory::describeEnemyType(const Enemy& e) {
    std::cout << "Enemy type: " << e.getName()
    << ", Level: " << e.getLevel()
    << ", HP: " << e.getHealth() << "\n";
}


