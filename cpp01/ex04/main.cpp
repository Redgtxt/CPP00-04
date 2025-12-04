#include <iostream>
#include <string>
#include <fstream>


int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        std::cout << "Wrong amount of elements" << std::endl;
        return 1;
    }

    std::string filenameReplace = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    filenameReplace.append(".replace");

    if(s1.empty())
    {
        std::cout << "Search string cannot be empty" << std::endl;
        return 1;
    }

    //Vou abrir o ficheiro
    std::ifstream Readfile(argv[1]);
    if(!Readfile)
    {
        std::cout << "File invalid" << std::endl;
        return 1;
    }
    std::ofstream NewFile(filenameReplace.c_str());
    if(!NewFile)
    {
        std::cout << "Something occur while creating replace file" << std::endl;
        return 1;
    }
    std::string line;
    //Ler o arquivo
    bool firstLine = true;
    while (std::getline(Readfile, line))
    {
        if(!firstLine)
            NewFile << "\n";
        firstLine = false;
        
        size_t idx = 0; //index da ocorrencia de s1 no arquivo
        
        while ((idx = line.find(s1, idx)) != std::string::npos)
        {
            line.erase(idx, s1.length());
            line.insert(idx, s2);
            idx += s2.length();//move o indicador
        }
        NewFile << line;
    }

    Readfile.close();
    NewFile.close();

    return 0;
}

