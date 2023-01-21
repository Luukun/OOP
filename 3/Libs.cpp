#include "Libs.h"

std::string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


Buffer::Buffer (char top, char mid, char bot)
{
    size = 0;
    buffer = 0;
    if (top != 0)
    {
        buffer = static_cast <int> (top) << 16;
        size = 1;

        if (mid != 0)
        {
            buffer |= static_cast <int> (mid) << 8;
            size = 2;
            if (bot != 0)
            {
                buffer |= static_cast <int> (bot);
                size = 3;
            }
        }
        
    }
}

std::string check_coding (std::string& str)
{
    std::string result = "";
    std::string::iterator it = str.begin();

            while (str.end() - it >= 3)
            {
                Buffer buffer (*it, *(it + 1), *(it + 2));
                result += buffer.coding();

                it += 3;
            }

            if (str.end() - it == 2)
            {
                Buffer buffer (*it, *(it + 1));
                result += buffer.coding();
            }

            if (str.end() - it == 1)
            {
                Buffer buffer (*it);
                result += buffer.coding();
            }

    return result;
}

std::string check_decoding (std::string& str)
{
    std::string::iterator it = str.begin();
    std::string result = "";

            while (it != str.end())
            {
                Buffer buffer;
                std::string iteration  (it, it + 4);
                buffer.decoding (iteration);

                result += buffer.get_buf();

                it += 4;
            }

    return result;
}

std::string Buffer::coding()
{
    int s1, s2, s3, s4;

    if (size > 0)
    {
        s1 = buffer >> 18;
        s2 = (buffer >> 12) & 63;

        if (size > 1)
            s3 = (buffer >> 6) & 63;

        if (size > 2)
            s4 = buffer & 63;
    
    }

    std::string res (4, '=');

    switch (size)
    {
        case 3:
            res[3] = BASE64[s4];
        
        case 2:
            res[2] = BASE64[s3];
        
        case 1:
            res[0] = BASE64[s1];
            res[1] = BASE64[s2];
            break;
    }

    return res;
}

void Buffer::decoding(std::string buf)
{
    
    buffer = BASE64.find (buf[0]) << 18;
    
    buffer |= BASE64.find (buf[1]) << 12;

    size = 1;

    if (buf[2] != '=')
    {
        buffer |= BASE64.find (buf[2]) << 6;
        size = 2;
    }
    
    if (buf[3] != '=')
    {
        buffer |= BASE64.find (buf[3]);
        size = 3;
    }

}

std::string Buffer::get_buf()
{
    std::string res (size, '=');
    res[0] = static_cast<char> (buffer >> 16);
    res[1] = static_cast<char> ((buffer >> 8) & 255);
    res[2] = static_cast<char> (buffer & 255);

    return res;
}

std::string to_binary (int val, int n) 
{
    std::string res (n, '0'); 

    for (int i = n - 1; i >= 0; i--)
    {
        if (static_cast <int> (val / pow (2, i)) == 1) 
        {
            res[n - 1 - i] = '1'; 
            val -= pow (2, i); 
        }
    }

    return res;
}