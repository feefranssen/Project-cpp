#ifndef GAME_H
#define GAME_H

#include "Hero.h"
#include "Enemy.h"
#include "GameFactory.h"
#include "Utils.h"

#include <vector>
#include <memory>
#include <string>

namespace Game {

struct CombatLog {
    std::vector<std::string> entries;
    void add(const std::string& text) { entries.push_back(text); }
};

class Game {
private:
    std::shared_ptr<Character> hero;
    std::vector<std::shared_ptr<Character>> enemies;    // Vraag 36 – useful container
    CombatLog* combatLog;

    void combatLoop();

public:
    Game();
    ~Game();
    void startGame();

    int getHeroHP() const;
    int getEnemyHP() const;
    void stepCombat();  // voer 1 ronde uit
    void resetGame();   // hero + enemies opnieuw aanmaken
};

}

#endif
