#include "Weapon.hpp"

Weapon::Weapon(std::string typeWeapon) : type(typeWeapon)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(const std::string& NewType) 
{
    this->type = NewType;
}

const std::string& Weapon::getType() const
{
    return this->type;
}