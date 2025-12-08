#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    std::cout << "Default constructor called!" << std::endl;
}


Zombie::Zombie(std::string zombieName) : name(zombieName)
{
    std::cout << "🧟 Zombie '" << name << "' has been created!" << std::endl;
}


Zombie::~Zombie()
{
    std::cout << "💀 Zombie '" << name << "' has been destroyed!" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name; 
}

void Zombie::getName() const
{ 
    std::cout << name << std::endl; 
}

