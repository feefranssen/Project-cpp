#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

namespace Game {

class Weapon {
private:
    std::string name;
    unsigned char baseDamage;  //Vraag 4 – Correct protections

public:
    Weapon();
    Weapon(const std::string& name, unsigned char baseDamage);  // Vraag 29 – const reference
    Weapon(const Weapon& other);
    Weapon& operator=(const Weapon& other);

    std::string getName() const;
    int getDamage() const;
    int getBaseDamage() const { return static_cast<int>(baseDamage); }

    int compare(const Weapon& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Weapon& w); // Vraag 26 – friend function
    friend bool operator>(const Weapon& lhs, const Weapon& rhs);
};

}

#endif
