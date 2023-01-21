#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <stack>
#include <vector>
#include <cmath>

class Record
{
    std::string input_str;
    int result;
    int this_index;
    std::stack <int> st;

    public:

        Record(std::string s);
        void run();
        int get_result ();

};


#endif