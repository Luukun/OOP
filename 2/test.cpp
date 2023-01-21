#include "gtest/gtest.h"
#include "String.h"

TEST(StringTest, StringGetRes)
{

    String string1 ("    hello    World   ");
    string1.upped_word();
    string1.trimmed();
    String string2 ("#");
    string2 += string1;
    EXPECT_EQ("#HelloWorld", string2.get_str());

    String string3 (" f f f f f");
    string1.upped_word();
    string1.trimmed();
    String string4 ("#");
    string4 += string3;
    EXPECT_EQ("#FFFFF", string4.get_str());
    EXPECT_EQ("No error", check (string3).what());

    String string5 ("");
    EXPECT_EQ("Input string is empty", check (string5).what());
}