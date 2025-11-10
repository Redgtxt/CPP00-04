#include <iostream>
#include <string>
#include <fstream>

/*
    argv[0] - filename
    argv[1] - string1
    argv[2] - string2

    trocar todo o que tiver string 1 pelo string2
*/

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
    //Vou criar o ficheiro novo .replace
    std::ofstream NewFile(filenameReplace.c_str());
    if(!NewFile)
    {
        std::cout << "Something occur while creating replace file" << std::endl;
        return 1;
    }

    std::cout << "File Created: " << filenameReplace << std::endl;
    
    //Vou abrir o ficheiro
    std::ifstream Readfile(argv[1]);
    if(!Readfile)
    {
        std::cout << "File invalid" << std::endl;
        return 1;
    }
    std::string content;
    size_t idx = 0; ; //index da ocorrencia de s1 no arquivo
    //Ler o arquivo
    while (std::getline(Readfile,content))
    {
        std::cout << content << std::endl;
        while (idx != std::string::npos)
        {
        idx = content.find(argv[2],content.length());
        content.erase(idx,s1.length());
        content.insert(idx,argv[3]);

        }
    }
    std::cout << "------------------------" << std::endl;
    std::cout << content << std::endl;
    std::cout << "Correu ate ao fim" << std::endl;
    Readfile.close();

    return 0;
}
