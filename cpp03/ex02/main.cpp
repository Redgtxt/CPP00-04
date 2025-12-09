#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== TEST ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== TEST ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.guard();
    scav.takeDamage(20);
    scav.beRepaired(10);

    std::cout << "\n=== TEST FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Boss");
    frag.highFivesGuys();
    frag.takeDamage(30);
    frag.beRepaired(15);

    std::cout << "\n=== DESTRUCTORS ===" << std::endl;
    return 0;
}