#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : name(humanName), wp_type(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    wp_type = &weapon;
}

void HumanB::attack()
{
    if (wp_type)
        std::cout << name << " attacks with their " << wp_type->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}