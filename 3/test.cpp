#include "gtest/gtest.h"
#include "Libs.h"

TEST(BufferTest, BufferGetRes)
{

    std::string str1 ("Manisof");
    EXPECT_EQ("TWFuaXNvZg==", check_coding (str1));

    std::string str2 ("AbdhYeban");
    EXPECT_EQ("QWJkaFllYmFu", check_coding (str1));

    std::string str3 ("UWlza2FNYW5zZGo=");
    EXPECT_EQ("QiskaMansdj", check_decoding (str1));

    std::string str4 ("QW5hbnNkdXFtSkpKSg==");
    EXPECT_EQ("AnansduqmJJJJ", check_decoding (str1));
}