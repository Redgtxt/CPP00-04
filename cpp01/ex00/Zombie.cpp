#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//Construtor do zombie permite inicializar um zombie com nome
Zombie::Zombie(std::string zombieName) : name(zombieName)
{
    std::cout << "🧟 Zombie '" << name << "' has been created!" << std::endl;
}

// Destrutor - importante para mostrar quando o zombie é destruído
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

