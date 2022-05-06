#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ValidParentheses.cpp"

using namespace std;

class ValidParenthesesTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

//example testcase
TEST_F(ValidParenthesesTest, example1) {

    string input = string("()");
    EXPECT_TRUE(s.isValid(input));
}

TEST_F(ValidParenthesesTest, example2) {

    string input = string("()[]{}");
    EXPECT_TRUE(s.isValid(input));
}

TEST_F(ValidParenthesesTest, example3) {

    string input = string("(]");
    EXPECT_FALSE(s.isValid(input));
}

//error input
TEST_F(ValidParenthesesTest, input1) {

    string input = string("abc");
    EXPECT_FALSE(s.isValid(input));
}

TEST_F(ValidParenthesesTest, input2) {

    string input = string("({abc})");
    EXPECT_FALSE(s.isValid(input));
}

TEST_F(ValidParenthesesTest, input3) {

    string input = string("[abc");
    EXPECT_FALSE(s.isValid(input));
}

//other input
TEST_F(ValidParenthesesTest, otherinput1) {

    string input = string("((()))");
    EXPECT_TRUE(s.isValid(input));
}

TEST_F(ValidParenthesesTest, otherinput2) {

    string input = string("((({}){}))");
    EXPECT_TRUE(s.isValid(input));
}

TEST_F(ValidParenthesesTest, otherinput3) {

    string input = string("((({}){})){([])}[{()}]");
    EXPECT_TRUE(s.isValid(input));
}