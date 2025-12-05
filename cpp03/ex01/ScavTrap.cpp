#include "ScavTrap.hpp"




ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "Copy constructor ScavTrap called" << std::endl;
    *this = obj;
}



ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;

    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_points = other.Energy_points;
        this->Attack_damage = other.Attack_damage;
    }
    
    return *this;
}


ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default ScavTrap Constructor called" << std::endl;
        this->Hit_points = 100;
        this->Energy_points = 50;
        this->Attack_damage = 20;

}

    ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
    {
    std::cout<< this->Name << " ScavTrap Constructor called" << std::endl;
        
        this->Hit_points = 100;
        this->Energy_points = 50;
        this->Attack_damage = 20;
    }

void ScavTrap::guard()
{
    std::cout << this->Name << " is now guarding the gate" << std::endl;        
}

void ScavTrap::attack(const std::string& target)
{
    if(this->Energy_points > 0 && this->Hit_points > 0)
    {
        this->Energy_points--;
        std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    }else{
         std::cout << "ScavTrap " << this->Name << " is out of energy or dead!" << std::endl;
    }
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called" << std::endl;

}