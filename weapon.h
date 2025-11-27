#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <random>
#include <iostream>

namespace Game {

class Weapon {
private:
    std::string name;
    int baseDamage;

public:
    Weapon(); // default constructor
    Weapon(const std::string& name, int baseDamage); // parameterized constructor
    Weapon(const Weapon& other); // copy constructor

    std::string getName() const;
    int getDamage() const;

    // Friend function for printing
    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
};

}

#endif // WEAPON_H
