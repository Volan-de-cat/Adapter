#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "XorCrypto.h"
#include "ReadWrite.h"

int main()
{
    try {
        std::string path;
        std::cout << "Enter file path: ";
        getline(std::cin, path);
        ReadWrite file(std::make_unique<XorCrypto>(), path, std::ios::in | std::ios::out | std::ios::app);
        std::string key;
        std::cout << "Enter key: ";
        getline(std::cin, key);

        char mode;
        std::cout << "Enter file mode (r/w): ";
        std::cin >> mode;

        std::string line = "";

        switch (mode)
        {
        case 'R':
        case 'r':
        {
            while (!(line = file.ReadString(key)).empty())
            {
                std::cout << line << std::endl;
            }
            break;
        }
        case 'W':
        case 'w':
        {
            std::cout << "Enter string:" << std::endl;

            std::cin.ignore();
            getline(std::cin, line);
            while (!line.empty())
            {  
                file.WriteString(line, key);
                getline(std::cin, line);
            }
            break;
        }
        default:
            std::cout << "Invalid Mode" << std::endl;
            break;
        }
    }
    catch (std::exception& ex) 
    {
        std::cout << "Exeption: " << ex.what() << std::endl;
    }
    
    _getch();
    return 0;
}