#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* wp_type;
public:
    HumanB(std::string humanName);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack();
};


