#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <stdexcept>

namespace Game {

Game::Game() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Hero aanmaken
    hero = std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());

    // Initial enemy
    enemies.push_back(GameFactory::spawnRandomEnemy());

    // Combat log aanmaken
    combatLog = new CombatLog();        // Vraag 32 – dynamic memory allocation

}

Game::~Game() {
    delete combatLog;      // Vraag 33 – dynamic memory removing
    combatLog = nullptr;    // Vraag 37 – nullptr usage
}

void Game::startGame() {    // Vraag 8 – fully working project
    combatLoop();
}

void Game::combatLoop() {
    int round = 1;

    while (hero->getIsAlive() && !enemies.empty()) {
        std::cout << "\n=== Ronde " << round << " ===\n";

        // Poison schade van hero
        std::dynamic_pointer_cast<Hero>(hero)->handlePoison();

        // Hero valt eerste enemy aan
        hero->attack(*enemies.front());
        combatLog->add(hero->getName() + " attacks " + enemies.front()->getName());

        if (!enemies.front()->getIsAlive()) {
            combatLog->add(enemies.front()->getName() + " is defeated");
            std::cout << enemies.front()->getName() << " is verslagen!\n";
            enemies.erase(enemies.begin());
            round++;
            continue;
        }

        // Enemies vallen hero aan
        for (size_t i = 0; i < enemies.size(); ++i) {
            auto enemy = std::dynamic_pointer_cast<Enemy>(enemies[i]);
            enemy->attack(*hero);
            combatLog->add(enemy->getName() + " attacks " + hero->getName());

            // Spawn extra enemy indien nodig
            if (rand() % 100 < 20 && enemies.size() < 2) {
                auto newEnemy = GameFactory::spawnRandomEnemy();
                enemies.push_back(newEnemy);
                combatLog->add(enemy->getName() + " summons " + newEnemy->getName());

                std::cout << enemy->getName() << " roept een extra enemy op: "
                          << newEnemy->getName() << "!\n";
            }
        }

        // Heal kans voor hero
        if (rand() % 100 < 30) {
            std::dynamic_pointer_cast<Hero>(hero)->heal(5);
            combatLog->add(hero->getName() + " heals");
        }

        // Status na ronde
        std::cout << "\nStatus na ronde " << round << ":\n";
        std::cout << *hero << "\n";
        for (auto& e : enemies) std::cout << *e << "\n";

        round++;
    }

    std::cout << "\n=== Gevecht afgelopen ===\n";

    const Character& heroRef = *hero; // Vraag 29 – const reference variable
    std::cout << heroRef << "\n";

    for (const auto& e : enemies) {
        const Character& enemyRef = *e; // Vraag 29 – const reference variable
        std::cout << enemyRef << "\n";
    }

    auto saveGame = [&](const Hero& hero) {    // Vraag 40 – lambda function
            const Hero& heroRef = hero; // Vraag 29 – const reference variable

        try {    // Vraag 39 – exception handling
            std::ofstream out("save.txt");  // Vraag 38 – modern file I/O
            if (!out) throw std::runtime_error("Kan save.txt niet openen");

            out << "Hero " << hero.getName() << " "
                << hero.getHealth() << " "
                << hero.getLevel() << "\n";

            for (auto& e : enemies) {
                out << "Enemy " << e->getName()
                << " " << e->getHealth()
                << " " << e->getLevel() << "\n";
            }

            out << "\n--- Combat log ---\n";
            for (const auto& entry : combatLog->entries) out << entry << "\n";

            std::cout << "Game opgeslagen in save.txt\n";
        } catch (const std::exception& ex) {
            std::cerr << "Save error: " << ex.what() << "\n";
        }
    };

    std::thread saveThread(saveGame, *std::dynamic_pointer_cast<Hero>(hero)); //Vraag 41 – useful usage of threads
    saveThread.join();
}

//gui
int Game::Game::getHeroHP() const {
    return hero->getHealth();
}

int Game::Game::getEnemyHP() const {
    return enemies.empty() ? 0 : enemies.front()->getHealth();
}

void Game::Game::stepCombat() {
    if (!hero->getIsAlive() || enemies.empty() || !enemies.front()->getIsAlive())
        return;

    // Hero valt aan
    hero->attack(*enemies.front());
    if (!enemies.front()->getIsAlive())
        enemies.erase(enemies.begin());

    // Enemy valt terug als hij leeft
    if (!enemies.empty() && enemies.front()->getIsAlive())
        enemies.front()->attack(*hero);
}

void Game::Game::resetGame() {
    hero = std::make_shared<Hero>("Arthur", 40, GameFactory::getRandomHeroWeapon());
    enemies.clear();
    enemies.push_back(GameFactory::spawnRandomEnemy());
}



}
