#include "Libs.h"
#include <iostream>

int main()
{
    std::cout << "Choose mode:\n1 - Text to Base64\n2 - Base64 to Text\n";

    int val;

    std::cin >> val;

    std::string str, result = "";
    std::cin >> str;

    switch (val)
    {
        case 1:
        {
            std::string::iterator it = str.begin();

            while (str.end() - it >= 3)
            {
                Buffer buffer (*it, *(it + 1), *(it + 2));
                result += buffer.coding();

                it += 3;
            }

            if (str.end() - it == 2)
            {
                Buffer buffer (*it, *(it + 1));
                result += buffer.coding();
            }

            if (str.end() - it == 1)
            {
                Buffer buffer (*it);
                result += buffer.coding();
            }

            break;
        }

        case 2:
        {
            std::string::iterator it = str.begin();

            while (it != str.end())
            {
                Buffer buffer;
                std::string iteration  (it, it + 4);
                buffer.decoding (iteration);

                result += buffer.get_buf();

                it += 4;
            }

            break;
        }
    }

    std::cout << result << std::endl;
}

