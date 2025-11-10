#include "Zombie.hpp"

int main(void)
{
    Zombie *horde;
    int number_of_zombies = 10;
    horde = zombieHorde(number_of_zombies,"Miau");
    //Print 
    for (int i = 0; i < number_of_zombies; i++)
    {
        horde[i].announce();
    }
    delete[] horde;

}