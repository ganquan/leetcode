#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "StringToInteger_atoi.cpp"

using namespace std;

class StringToInteger_atoiTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

//example testcase
TEST_F(StringToInteger_atoiTest, example1) {

    string input = string("42");
    EXPECT_EQ(s.myAtoi(input), 42);
}

TEST_F(StringToInteger_atoiTest, example2) {

    string input = string("   -42");
    EXPECT_EQ(s.myAtoi(input), 42);
}

TEST_F(StringToInteger_atoiTest, example3) {

    string input = string("4193 with words");
    EXPECT_EQ(s.myAtoi(input), 4193);
}
