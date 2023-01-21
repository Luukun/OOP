#include "Record.h"
#include <iostream>

Record::Record (std::string s) : input_str (s), result (0)
{
    this_index = 0;
}

void Record::run()
{
    while (this_index < input_str.size())
    {
        if (input_str[this_index] >= '0' && input_str[this_index] <= '9')
        {
            std::vector <char> vec_ch;
            while (input_str[this_index] >= '0' && input_str[this_index] <= '9')
            {
                vec_ch.push_back (input_str[this_index]);
                this_index++;
            }

            int res = 0;

            for (int i = 0; i < vec_ch.size(); i++)
            {
                res += pow (10, vec_ch.size() - i - 1) * static_cast<int> (vec_ch[i] - '0');
            }

            st.push (res);
        }

        if (input_str[this_index] == '+' || input_str[this_index] == '*')
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if (input_str[this_index] == '+')
                st.push(first + second);
            
            if (input_str[this_index] == '*')
                st.push (first * second);
        }

        this_index++;
    }

    result = st.top();
}

int Record::get_result()
{
    return result;
}