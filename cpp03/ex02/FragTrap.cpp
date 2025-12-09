#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << this->Name << " FragTrap Constructor called" << std::endl;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;  
}

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap Constructor called" << std::endl;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;  
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "Copy constructor FragTrap called" << std::endl;
    *this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    std::cout << "Copy assignment operator FragTrap called" << std::endl;
    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_points = other.Energy_points;
        this->Attack_damage = other.Attack_damage;
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if(this->Energy_points > 0 && this->Hit_points > 0)
    {
        this->Energy_points--;
        std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    }else{
         std::cout << "FragTrap " << this->Name << " is out of energy or dead!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->Name << " WOW I'm so happy to be a robot will you be nice to me and give me a high five?" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap Called" << std::endl;
}

