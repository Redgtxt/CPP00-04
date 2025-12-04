#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& weapon) : name(humanName) , wp_type(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << wp_type.getType() << std::endl;
}