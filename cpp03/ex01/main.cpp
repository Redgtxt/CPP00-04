#include "ScavTrap.hpp"

/*

int main()
{
    std::cout << "--- TEST 1: Constructors ---" << std::endl;
    ClapTrap robotA("RobotA");
    ClapTrap robotB("RobotB");

    std::cout << "\n--- TEST 2: Attack and Energy Consumption ---" << std::endl;
    // RobotA ataca RobotB
    robotA.attack("RobotB");
    robotB.takeDamage(0); // Dano do ataque padrão é 0 no ex00

    std::cout << "\n--- TEST 3: Taking Damage and Repairing ---" << std::endl;
    // RobotB recebe dano
    robotB.takeDamage(5);
    
    // RobotB se repara (recupera vida, gasta 1 energia)
    robotB.beRepaired(3);

    std::cout << "\n--- TEST 4: Depleting Energy ---" << std::endl;
    // Forçar RobotA a gastar toda a energia (já gastou 1 no ataque acima)
    // ClapTrap tem 10 de energia inicial. Vamos gastar o resto.
    for (int i = 0; i < 10; i++)
        robotA.attack("Dummy");
    
    // Tentar atacar sem energia
    std::cout << ">> Trying to attack with no energy:" << std::endl;
    robotA.attack("Dummy");

    std::cout << "\n--- TEST 5: Death (0 Hit Points) ---" << std::endl;
    // RobotB recebe dano fatal
    robotB.takeDamage(20);
    
    // Tentar reparar estando morto
    std::cout << ">> Trying to repair while dead:" << std::endl;
    robotB.beRepaired(10);

    // Tentar atacar estando morto
    std::cout << ">> Trying to attack while dead:" << std::endl;
    robotB.attack("Dummy");

    return 0;
}
*/

int main()
{
    ScavTrap r1;
    ClapTrap *trap = &r1;
    trap->attack("banana");
    r1.attack("abacaxi");
    r1.guard();
    return 0;
}