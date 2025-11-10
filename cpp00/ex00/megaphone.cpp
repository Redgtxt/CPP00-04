/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei <hguerrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:54:40 by hguerrei          #+#    #+#             */
/*   Updated: 2025/09/02 15:54:51 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 
#include <string>

void printlowerToUpper(std::string str)
{

    for (size_t i = 0; i < str.length(); i++)
    {
        std::cout << (char)std::toupper(str[i]);
    }
    
}

int main(int argc,char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        printlowerToUpper(argv[i]);
    }
    std::cout << std::endl;

    return (0);
}
