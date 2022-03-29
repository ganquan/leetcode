#include <gtest/gtest.h>
#include <string>
#include "TribonacciNumber.cpp"


using namespace std;

// Constraints:

// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
class TribonacciNumberTest : public ::testing::Test {
 protected:
  void SetUp() override {
      s = Solution();
  }

  // void TearDown() override {}
  Solution s;
};

TEST_F(TribonacciNumberTest, 0) {
  EXPECT_EQ(0, s.tribonacci(0));
}

TEST_F(TribonacciNumberTest, 1) {
  EXPECT_EQ(1, s.tribonacci(1));
}

TEST_F(TribonacciNumberTest, 2) {
  EXPECT_EQ(1, s.tribonacci(2));
}

TEST_F(TribonacciNumberTest, 3) {
  EXPECT_EQ(2, s.tribonacci(3));
}

TEST_F(TribonacciNumberTest, 4) {
  EXPECT_EQ(4, s.tribonacci(4));
}

TEST_F(TribonacciNumberTest, 5) {
  EXPECT_EQ(7, s.tribonacci(5));
}

TEST_F(TribonacciNumberTest, 6) {
  EXPECT_EQ(13, s.tribonacci(6));
}