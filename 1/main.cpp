#include <iostream>
#include <vector>
#include <cmath>
#include "Matrix.h"

int main()
{
    int n;
    std::cout << "Input size of matrix - ";
    std::cin >> n;

    std::cout << "Input matrix A:\n";
    Matrix m (n);
    std::cin >> m;

    std::cout << "\n\n";

    std::vector <std::pair <int, int> > vec_p = m.find_min_index();

    std::cout << "Indices of smallest elements:\n";
    for (int i = 0; i < vec_p.size(); i++)
        std::cout << vec_p[i].first << " " << vec_p[i].second << "\n";
    
    std::cout << "\n\nSum of square of negative number: " << m.calculate_square_negative() << "\n\n";

    std::cout << "\n\nMinimum simple number: " << m.find_min_simple() << "\n\n";

    std::cout << "Input matrix B:\n";
    Matrix b(n), c(n);

    std::cin >> b;

    std::cout << "Input matrix C:\n";

    std::cin >> c;

    std::cout << "\n\nResult D = (B^T + C)^2:\n\n";

    Matrix d(n);
    d =  (b.transponse() + c) * (b.transponse() + c);

    std::cout << d;
}