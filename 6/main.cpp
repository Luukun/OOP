#include "Record.h"
#include <iostream>

int main()
{
    std::string input;
    std::cout << "Input string - ";
    std::getline (std::cin, input);

    Record rec (input);

    rec.run();

    std::cout << "result = " << rec.get_result() << std::endl;
}