#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

std::mutex mut;
std::vector <int> vec;
std::vector <int> vec_sum;
int sum = 0;
int n_threads;

void sum_func(int k)
{
    vec_sum[k] = 0;
    for (int i = k; i < vec.size(); i += n_threads)
    {
        vec_sum[k] += vec[i];
        mut.lock();
        std::cout << "Thread " << k << " vec[i] = " << vec[i] << " sum = " << sum << std::endl;
        mut.unlock();
        std::this_thread::sleep_for (std::chrono::milliseconds (100));
    }
}

int main()
{
    std::cout << "Enter the amount of threads - ";
    std::cin >> n_threads;

    std::cout << "Enter the size of vector - ";
    int size_vector;
    std::cin >> size_vector;

    vec = std::vector <int> (size_vector);

    std::cout << "Input vector:\n";
    for (int i = 0; i < size_vector; i++)
        std::cin >> vec[i];

    std::cout << "Vector:\n";

    for (int i = 0; i < size_vector; i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    std::thread * threads = new std::thread [n_threads];
    vec_sum = std::vector <int> (n_threads);

    for (int i = 0; i < n_threads; i++)
    {
        threads[i] = std::thread (sum_func, i);
    }

    for (int i = 0; i < n_threads; i++)
        threads[i].join();

    for (int i = 0; i < n_threads; i++)
        sum += vec_sum[i];

    std::cout << "sum = " << sum << std::endl;

}