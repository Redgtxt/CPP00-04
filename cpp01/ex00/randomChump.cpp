
#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie newZom(name);
    newZom.announce();
}
