#include <iostream>

int main()
{ 
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "=== ENDEREÇOS DE MEMÓRIA ===" << std::endl;
    std::cout << "Endereço de str:        " << &str << std::endl;
    std::cout << "Endereço em stringPTR:  " << stringPTR << std::endl;
    std::cout << "Endereço de stringREF:  " << &stringREF << std::endl;
    
    std::cout << "\n=== VALORES ===" << std::endl;
    std::cout << "Valor de str:        " << str << std::endl;
    std::cout << "Valor via stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valor via stringREF: " << stringREF << std::endl;

    return 0;
}