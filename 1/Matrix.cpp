#include "Matrix.h"

Matrix::Matrix (int n) : size (n)
{
    data = new int* [size];
    for (int i = 0; i < size; i++)
        data[i] = new int[size];
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; i++)
        delete[] data[i];
    
    delete[] data;
}

std::vector<std::pair <int, int> > Matrix::find_min_index()
{
    int min = data[0][0];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (data[i][j] < min)
                min = data[i][j];
    
    std::vector<std::pair <int, int> > temp_vec;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (data[i][j] == min)
                temp_vec.push_back (std::make_pair (i, j));
    
    return temp_vec;

}

long long Matrix::calculate_square_negative()
{
    long long sum = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (data[i][j] < 0)
                sum += pow (data[i][j], 2);

    return sum;
}

Matrix Matrix::transponse()
{
    Matrix m (size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            m.set_value (i, j, data[j][i]);

    return m;
}

void Matrix::set_value (int i, int j, int val)
{
    data[i][j] = val;
}

int Matrix::get_size()
{
    return size;
}

Matrix& Matrix::operator= (const Matrix& m)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = m.data[i][j];

    return *this;
}

Matrix operator+ (Matrix m1, Matrix m2)
{
    int size = m1.get_size();
    Matrix m (size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            m.set_value (i, j, m1.get_value(i,j) + m2.get_value(i, j));

    return m;
}

Matrix operator* (Matrix m1, Matrix m2)
{
    int size = m1.get_size();
    Matrix m (size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            long val = 0;

            for (int k = 0; k < size; k++)
                val += m1.get_value (i, k) * m2.get_value (k, j);

            m.set_value (i, j, val);
        }

    return m;
}

int Matrix::get_value (int i, int j)
{
    return data[i][j];
}

int Matrix::find_min_simple()
{
    if (size % 2 == 1)
        return -1;
    
    int half = size / 2;

    bool is_first = true;

    long min;

    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++)
            if (is_simple (data[i][j]))
            {
                if (is_first)
                {
                    min = data[i][j];
                    is_first = false;
                }
                else
                    if (data[i][j] < min)
                        min = data[i][j];
            }

    return min;
}

bool Matrix::is_simple(int val)
{

    for (int i = 2; i < val; i++)
        if (val % i == 0)
            return false;
    
    return true;
}

std::istream& operator>> (std::istream& c_in, Matrix& m)
{
    int size = m.get_size();

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            int val;
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> val;
            m.set_value (i, j, val);
        }
    
    return c_in;
}

std::ostream& operator<< (std::ostream& c_out, Matrix m)
{
    int size = m.get_size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << m.get_value(i, j) << " ";
        std::cout << std::endl;
    }

    return c_out;
}