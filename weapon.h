#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <random>

class Weapon {
private:
    std::string name;
    int baseDamage;

public:
    Weapon(const std::string& name, int baseDamage);
    std::string getName() const;
    int getDamage() const;
};

#endif // WEAPON_H
