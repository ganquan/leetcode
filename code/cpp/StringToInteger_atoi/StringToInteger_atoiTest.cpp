#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "StringToInteger_atoi.cpp"

using namespace std;

// Implement the myAtoi(string s) function, which converts a string to a 32-bit
// signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// 1. Read in and ignore any leading whitespace.
// 2. Check if the next character (if not already at the end of the string) is
// '-' or '+'. Read this character in if it is either. This determines if the
// final result is negative or positive respectively. Assume the result is
// positive if neither is present.
// 3. Read in next the characters until the next non-digit character or the end
// of the input is reached. The rest of the string is ignored.
// 4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If
// no digits were read, then the integer is 0. Change the sign as necessary
// (from step 2).
// 5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
// then clamp the integer so that it remains in the range. Specifically,
// integers less than -231 should be clamped to -231, and integers greater than
// 231 - 1 should be clamped to 231 - 1.
// 6. Return the integer as the final result.
// Note:

// Only the space character ' ' is considered a whitespace character.
// Do not ignore any characters other than the leading whitespace or the rest of
// the string after the digits.

class StringToInteger_atoiTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

// example testcase
TEST_F(StringToInteger_atoiTest, example1) {
    string input = string("42");
    EXPECT_EQ(s.myAtoi(input), 42);
}

TEST_F(StringToInteger_atoiTest, example2) {
    string input = string("   -42");
    EXPECT_EQ(s.myAtoi(input), -42);
}

TEST_F(StringToInteger_atoiTest, example3) {
    string input = string("4193 with words");
    EXPECT_EQ(s.myAtoi(input), 4193);
}

// zero input test
TEST_F(StringToInteger_atoiTest, zero_input_1) {
    string input = string("");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, zero_input_2) {
    string input = string("     ");
    EXPECT_EQ(s.myAtoi(input), 0);
}

// input test
TEST_F(StringToInteger_atoiTest, ignore_rule_1) {
    string input = string(" 1");
    EXPECT_EQ(s.myAtoi(input), 1);
}

TEST_F(StringToInteger_atoiTest, ignore_rule_2) {
    string input = string("  2");
    EXPECT_EQ(s.myAtoi(input), 2);
}

TEST_F(StringToInteger_atoiTest, ignore_rule_3) {
    string input = string("   3");
    EXPECT_EQ(s.myAtoi(input), 3);
}

TEST_F(StringToInteger_atoiTest, ignore_rule_4) {
    string input = string("    ");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, sign_rule_1) {
    string input = string("+123");
    EXPECT_EQ(s.myAtoi(input), 123);
}

TEST_F(StringToInteger_atoiTest, sign_rule_2) {
    string input = string("-1234");
    EXPECT_EQ(s.myAtoi(input), -1234);
}

TEST_F(StringToInteger_atoiTest, sign_rule_3) {
    string input = string("--1234");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, sign_rule_4) {
    string input = string("1234");
    EXPECT_EQ(s.myAtoi(input), 1234);
}

TEST_F(StringToInteger_atoiTest, sign_rule_5) {
    string input = string("++1234");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, rest_non_digit_ignore_rule_1) {
    string input = string("1234 ");
    EXPECT_EQ(s.myAtoi(input), 1234);
}

TEST_F(StringToInteger_atoiTest, rest_non_digit_ignore_rule_2) {
    string input = string("1234 abc");
    EXPECT_EQ(s.myAtoi(input), 1234);
}

TEST_F(StringToInteger_atoiTest, rest_non_digit_ignore_rule_3) {
    string input = string("1234.");
    EXPECT_EQ(s.myAtoi(input), 1234);
}

TEST_F(StringToInteger_atoiTest, rest_non_digit_ignore_rule_4) {
    string input = string("1234++");
    EXPECT_EQ(s.myAtoi(input), 1234);
}

TEST_F(StringToInteger_atoiTest, rest_non_digit_ignore_rule_5) {
    string input = string("12345ABC");
    EXPECT_EQ(s.myAtoi(input), 12345);
}

TEST_F(StringToInteger_atoiTest, convert_1) {
    string input = string("00134");
    EXPECT_EQ(s.myAtoi(input), 134);
}

TEST_F(StringToInteger_atoiTest, convert_2) {
    string input = string("0134");
    EXPECT_EQ(s.myAtoi(input), 134);
}

TEST_F(StringToInteger_atoiTest, convert_3) {
    string input = string("000-134");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, convert_4) {
    string input = string("abc");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, convert_5) {
    string input = string("+abc");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, convert_6) {
    string input = string("   -abc");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, convert_7) {
    string input = string("   -134abc");
    EXPECT_EQ(s.myAtoi(input), -134);
}

TEST_F(StringToInteger_atoiTest, convert_8) {
    string input = string("   134abc");
    EXPECT_EQ(s.myAtoi(input), 134);
}

TEST_F(StringToInteger_atoiTest, convert_9) {
    string input = string("   134 abc");
    EXPECT_EQ(s.myAtoi(input), 134);
}

TEST_F(StringToInteger_atoiTest, boundary_1) {
    // INT32_MAX + 1
    string input = string("   2147483648");
    EXPECT_EQ(s.myAtoi(input), INT32_MAX);
}

TEST_F(StringToInteger_atoiTest, boundary_2) {
    // INT32_MAX * 10
    string input = string("   21474836480");
    EXPECT_EQ(s.myAtoi(input), INT32_MAX);
}

TEST_F(StringToInteger_atoiTest, boundary_3) {
    // INT32_MIN - 1
    string input = string("   -2147483648");
    EXPECT_EQ(s.myAtoi(input), INT32_MIN);
}

TEST_F(StringToInteger_atoiTest, boundary_4) {
    // INT32_MIN * 10
    string input = string("   -21474836480");
    EXPECT_EQ(s.myAtoi(input), INT32_MIN);
}

TEST_F(StringToInteger_atoiTest, boundary_5) {
    // INT32_MIN * 100
    string input = string("   -214748364800");
    EXPECT_EQ(s.myAtoi(input), INT32_MIN);
}

TEST_F(StringToInteger_atoiTest, boundary_6) {
    // INT32_MAX * 100
    string input = string("   21474836480");
    EXPECT_EQ(s.myAtoi(input), INT32_MAX);
}

TEST_F(StringToInteger_atoiTest, combined_1) {
    // https://leetcode.com/submissions/detail/694333889/
    //  Input:
    //  "00000-42a1234"
    //  Output:
    //  -42
    //  Expected:
    //  0
    string input = string("00000-42a1234");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, combined_2) {
    string input = string("00000-42-");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, combined_3) {
    // https://leetcode.com/submissions/detail/694338046/
    // Input:
    // "3.14159"
    // Output:
    // 0
    // Expected:
    // 3
    string input = string("3.14159");
    EXPECT_EQ(s.myAtoi(input), 3);
}

TEST_F(StringToInteger_atoiTest, combined_4) {
    // https://leetcode.com/submissions/detail/694342785/
    // Input:
    // "  -0012a42"
    // Output:
    // 0
    // Expected:
    // -12
    string input = string("  -0012a42");
    EXPECT_EQ(s.myAtoi(input), -12);
}

TEST_F(StringToInteger_atoiTest, combined_5) {
    // https://leetcode.com/submissions/detail/694371346/
    // Input:
    // "   +0 123"
    // Output:
    // 123
    // Expected:
    // 0
    string input = string("   +0 123");
    EXPECT_EQ(s.myAtoi(input), 0);
}

TEST_F(StringToInteger_atoiTest, combined_6) {
    // https://leetcode.com/submissions/detail/694378859/
    // Input:
    // "20000000000000000000"
    // Output:
    // 0
    // Expected:
    // 2147483647
    string input = string("20000000000000000000");
    EXPECT_EQ(s.myAtoi(input), 2147483647);
}

TEST_F(StringToInteger_atoiTest, combined_7) {
    // https://leetcode.com/submissions/detail/694390406/
    // Input:
    // "123-"
    // Output:
    // -123
    // Expected:
    // 123
    string input = string("123-");
    EXPECT_EQ(s.myAtoi(input), 123);
}