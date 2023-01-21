#include "String.h"

String::String()
{

}

String::String (std::string s) : str (s)
{}

String& String::operator= (String& s)
{
    str = s.str;
    return *this;
}

std::string String::get_str()
{
    return str;
}

std::runtime_error check(String s_in)
{
    try
    {
        if (s_in.length() > 100)
            throw std::runtime_error ("Input string is very long");
        if (s_in.length() == 0)
            throw std::runtime_error ("Input string is empty");
    }    
    catch (std::runtime_error e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return e;
    }

    return std::runtime_error ("No error");
}

void String::trimmed()
{
    for (int i = 0; i < str.length(); )
    {
        if (str[i] == ' ')
            str.erase (str.begin() + i);
        else
            i++;
    }
}

int String::length()
{
    return str.length();
}

void String::upped_word()
{
    bool is_first = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            is_first = true;
        else
        {
            if (is_first)
            {
                if (str[i] >= 97 && str[i] <= 122)
                    str[i] -= 32;

                is_first = false;
                
            }
        }
    }
}

std::istream& operator>> (std::istream& c_in, String& s)
{
    std::getline (std::cin, s.str);
    return c_in;
}

std::ostream& operator<< (std::ostream& c_out, String s)
{
    std::cout << s.str;
    return c_out;
}

String String::operator+= (String s)
{
    str += s.str;
    return *this;
}