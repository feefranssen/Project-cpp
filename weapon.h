#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

namespace Game {

class Weapon {
private:
    std::string name;
    unsigned char baseDamage;

public:
    Weapon();
    Weapon(const std::string& name, unsigned char baseDamage);
    Weapon(const Weapon& other);
    Weapon& operator=(const Weapon& other);

    std::string getName() const;
    int getDamage() const;

    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
};

}

#endif
