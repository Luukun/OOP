#include <iostream>
#include <string>
#include "String.h"
#include <stdexcept>



int main()
{
    String s_in, s_out("#");

    std::cin >> s_in;

    try
    {
        if (s_in.length() > 100)
            throw std::runtime_error ("Input string is very long");
        if (s_in.length() == 0)
            throw std::runtime_error ("Input string is empty");
    }    
    catch (std::runtime_error e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    s_in.upped_word();
    s_in.trimmed();


    s_out += s_in;

    std::cout << s_out << "\n";
}