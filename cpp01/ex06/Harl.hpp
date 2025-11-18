#include <iostream>
#include <string>
class Harl
{
private:

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    typedef void (Harl::*functions)();
    functions funcs[4];


void complain(std::string level);
};


