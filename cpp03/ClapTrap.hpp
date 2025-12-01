#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    int Hit_points;
    int Energy_points;
    int Attack_damage;
public:
    ClapTrap(/* args */);
    ClapTrap(const ClapTrap &obj);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};


ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if(this != &other)
        
    
    return *this;
}

ClapTrap::ClapTrap() : Name("Default"), Hit_points(10),Energy_points(10),Attack_damage(0)
{
}

ClapTrap::~ClapTrap()
{
}
//Atacar e reparar custa 1 de energia
//ClapTrap nao pode fazer nada se nao tem pontos
//Target vai perder hit_points
void ClapTrap::attack(const std::string& target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

//Quando se repara vai ganhar aumentar os hit_points com base no amount
void  ClapTrap::beRepaired(unsigned int amount)
{

}
