#include <iostream>

class WrongAnimal
{
protected:
    std::string type;//tipo de animal
    
public:
    WrongAnimal();
    WrongAnimal(std::string name);
    WrongAnimal(const WrongAnimal &obj);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();
    void makeSound() const;
    const std::string& getType(void) const;
};
