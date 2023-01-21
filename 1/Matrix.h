#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>


class Matrix
{
    int ** data;
    int size;

    public:

        Matrix (int);
        ~Matrix();
        std::vector<std::pair <int, int> > find_min_index ();
        long long calculate_square_negative ();
        Matrix transponse  ();
        int get_size();
        Matrix& operator= (const Matrix&);
        friend Matrix operator+ (Matrix, Matrix);
        friend std::istream& operator>> (std::istream&, Matrix&);
        friend std::ostream& operator<< (std::ostream&, Matrix);
        friend Matrix operator* (Matrix, Matrix);

        int find_min_simple ();
        static bool is_simple (int val);

        void set_value (int, int, int);
        int get_value (int, int);

};



#endif