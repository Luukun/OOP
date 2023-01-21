#ifndef LIBS_H
#define LIBS_H
#include <string>
#include <cmath>
#include <iostream>
extern std::string BASE64;


class Buffer
{
    int buffer;
    int size;
    
    public:
        Buffer (char top = 0, char mid = 0, char bot = 0);
        std::string coding ();
        void decoding (std::string buf);
        std::string get_buf ();

};

std::string to_binary (int val, int n);
std::string check_coding (std::string& str);
std::string check_decoding (std::string& str);


#endif