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
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &obj);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


    int getHitPoints();
};

