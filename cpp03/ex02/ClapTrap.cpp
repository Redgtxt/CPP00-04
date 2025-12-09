#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit_points(10),Energy_points(10),Attack_damage(0)
{
    std::cout << "Default ClapTrap Constructor called" << std::endl;

}

ClapTrap::ClapTrap(std::string name) : Name(name), Hit_points(10),Energy_points(10),Attack_damage(0)
{
    std::cout << "Constructor ClapTrap with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor ClapTrap called" << std::endl;
    *this = obj;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment ClapTrap operator called" << std::endl;

    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_points = other.Energy_points;
        this->Attack_damage = other.Attack_damage;
    }
    
    return *this;
}




ClapTrap::~ClapTrap()
{
    std::cout << "Destructor ClapTrap called" << std::endl;

}

void ClapTrap::attack(const std::string& target)
{
    if(this->Energy_points > 0 && this->Hit_points > 0)
    {
        this->Energy_points--;
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    }else{
         std::cout << "ClapTrap " << this->Name << " is out of energy or dead!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->Hit_points > 0)
    {
		std::cout<<"ClapTrap "<< this->Name<< " took " <<amount<<" point(s) of damage!"<< std::endl;
        this->Hit_points -= amount;
    }else
    {
        std::cout<<"ClapTrap "<< this->Name<< " is already dead"<< std::endl;
    }
}


//Quando se repara vai ganhar aumentar os hit_points com base no amount
void  ClapTrap::beRepaired(unsigned int amount)
{
    if(this->Energy_points > 0 && this->Hit_points > 0)
    {
        this->Hit_points += amount;
        this->Energy_points--;
        std::cout<<"ClapTrap " << this->Name << " repairs itself, getting " << amount << " hit points back!" << std::endl;
    }else{
         std::cout<<"ClapTrap " << this->Name << " is out of energy!" << std::endl;
    }

}

int ClapTrap::getHitPoints()
{
    return Hit_points;
}