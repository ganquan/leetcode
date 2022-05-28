#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "RegularExpressionMatching.cpp"

using namespace std;


class RegularExpressionMatchingTest : public ::testing::Test {
 protected:
    void SetUp() override { sln = Solution(); }

    // void TearDown() override {}
    Solution sln;
};

// example testcase
TEST_F(RegularExpressionMatchingTest, example1) {
    string s = string("aa");
    string p = string("a");

    bool expect = false;

    EXPECT_EQ(sln.isMatch(s, p), expect);
}

TEST_F(RegularExpressionMatchingTest, example2) {
    string s = string("aa");
    string p = string("a*");

    bool expect = true;

    EXPECT_EQ(sln.isMatch(s, p), expect);
}

TEST_F(RegularExpressionMatchingTest, example3) {
    string s = string("ab");
    string p = string(".*");

    bool expect = true;

    EXPECT_EQ(sln.isMatch(s, p), expect);
}

//failure case 
TEST_F(RegularExpressionMatchingTest, fail1) {
    string s = string("aab");
    string p = string("c*a*b");

    bool expect = true;

    EXPECT_EQ(sln.isMatch(s, p), expect);
}
