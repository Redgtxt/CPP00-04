#pragma once
#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string typeWeapon);
    ~Weapon();
    void setType(const std::string& NewType);
    const std::string& getType() const;
};

