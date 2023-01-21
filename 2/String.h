#ifndef STRING_H
#define STRING_H
#include <string>
#include <vector>
#include <iostream>

class String
{
    std::string str;

    public:

        String ();
        String (std::string s);
        int length();
        friend std::istream& operator>> (std::istream& c_in, String& s);
        friend std::ostream& operator<< (std::ostream& c_in, String s);
        std::string get_str ();
        void trimmed ();
        String& operator= (String& s);
        void upped_word ();
        String operator+= (String s);


};

std::runtime_error check(String str_in);



#endif