#include "gtest/gtest.h"
#include "Record.h"

TEST(RecordTest, RecordGetResult)
{

    std::string str1 ("1 2 2 * + 1 + 2 2 * + 1 +");
    Record rec1 (str1);
    rec1.run();
    EXPECT_EQ(11, rec1.get_result());

    std::string str2 ("1 2 + 1 2 * +");
    Record rec2 (str2);
    rec2.run();
    EXPECT_EQ(5, rec2.get_result());
}