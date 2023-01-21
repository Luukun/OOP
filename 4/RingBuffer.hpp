#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include <iostream>


template <class T>
class RingBuffer
{
    bool is_full;
    int pos_tail;
    int size;
    int n_obj;
    T * data;

    public:

        RingBuffer(int n) : size (n)
        {
            data = new T [n];
            pos_tail = -1;
            n_obj = 0;
            is_full = false;
        }


        void add (T val)
        {

            if (pos_tail == -1)
            {
                pos_tail = 0;
                data[0] = val;
            }

            data[pos_tail] = val;

            if (pos_tail == size - 1)
                pos_tail = 0;
            else
                pos_tail++;
            


            if (!is_full)
            {
                n_obj++;
                if (n_obj == size)
                    is_full = true;
            }
        }

        int get_size()
        {
            return size;
        }

        int tail()
        {
            return pos_tail;
        }

        bool full()
        {
            return is_full;
        }

        T get_value (int index)
        {
            return data[index];
        }

        friend std::ostream& operator<< (std::ostream& c_out, RingBuffer rb)
        {
            for (int i = 0; i < rb.get_size(); i++)
            {
                if (!rb.full() && i > rb.tail() - 1)
                    std::cout << "<empty> ";
                else
                    std::cout << rb.get_value(i) << " ";
            }

            std::cout << "\n";

            return c_out;
        }
    
};


#endif