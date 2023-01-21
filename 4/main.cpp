#include "RingBuffer.hpp"

int main()
{
    std::cout << "Size of buffer:\n";
    int n;
    std::cin >> n;

    RingBuffer <int> rb (n);

    while (1)
    {
        std::cout << "1 - Add\n2 - Print\n3 - Exit\n";
        int choose;
        std::cin >> choose;

        switch (choose){
            case 1:
            {
                std::cout << "Input data - ";
                int val;
                std::cin >> val;

                rb.add (val);

                break;
            }

            case 2:
            {
                std::cout << rb << std::endl;
                break;
            }

            case 3:
            {
                return 0;
            }
        }
    }
}