#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <random>

class Weapon {
private:
    std::string name;
    int baseDamage;

public:
    Weapon(); // default constructor (forwarded)
    Weapon(const std::string& name, int baseDamage); // parameterized constructor
    Weapon(const Weapon& other); // copy constructor

    std::string getName() const;
    int getDamage() const;
};

#endif // WEAPON_H
