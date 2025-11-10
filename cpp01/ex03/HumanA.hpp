#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon&  wp_type;
public:
    HumanA(std::string humanName, Weapon& weapon);
    ~HumanA();
    void attack();
};


