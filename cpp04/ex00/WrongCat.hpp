#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &obj);
    WrongCat& operator=(const WrongCat& other);
    void makeSound() const;
    ~WrongCat();
};



