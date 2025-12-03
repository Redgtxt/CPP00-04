#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "   STACK vs HEAP ALLOCATION DEMO" << std::endl;
    std::cout << "========================================\n" << std::endl;

    std::cout << "📦 [STACK] Creating zombie on the stack..." << std::endl;
    Zombie z1("StackZombie");
    z1.announce();
    std::cout << "   ℹ️  Stack zombies are destroyed automatically at end of scope\n" << std::endl;

    std::cout << "----------------------------------------\n" << std::endl;

    std::cout << "🔷 [HEAP] Creating zombie on the heap with newZombie()..." << std::endl;
    Zombie *z2 = newZombie("HeapZombie");
    z2->announce();
    std::cout << "   ℹ️  Heap zombies persist beyond function scope" << std::endl;
    std::cout << "   ⚠️  Must manually delete to avoid memory leak!\n" << std::endl;

    std::cout << "----------------------------------------\n" << std::endl;

    std::cout << "⚡ [STACK] Using randomChump() - temporary zombie..." << std::endl;
    randomChump("TempZombie");
    std::cout << "   ℹ️  Notice: zombie destroyed immediately after announce!\n" << std::endl;

    std::cout << "----------------------------------------\n" << std::endl;

    std::cout << "🧹 Cleaning up heap zombie..." << std::endl;
    delete z2;

    std::cout << "\n========================================" << std::endl;
    std::cout << "   END OF PROGRAM" << std::endl;
    std::cout << "   Stack zombie will be destroyed now..." << std::endl;
    std::cout << "========================================\n" << std::endl;

    return 0;
}
