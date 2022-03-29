#include <gtest/gtest.h>
#include <string>
#include "FibonacciNumber.cpp"


using namespace std;

// Constraints:
// 1 <= n <= 45


class FibonacciNumberTest : public ::testing::Test {
 protected:
  void SetUp() override {
      s = Solution();
  }

  // void TearDown() override {}
  Solution s;
};

TEST_F(FibonacciNumberTest, 0) {
  EXPECT_EQ(0, s.fib(0));
}

TEST_F(FibonacciNumberTest, 1) {
  EXPECT_EQ(1, s.fib(1));
}

TEST_F(FibonacciNumberTest, 2) {
  EXPECT_EQ(1, s.fib(2));
}

TEST_F(FibonacciNumberTest, 3) {
  EXPECT_EQ(2, s.fib(3));
}

TEST_F(FibonacciNumberTest, 4) {
  EXPECT_EQ(3, s.fib(4));
}

TEST_F(FibonacciNumberTest, 5) {
  EXPECT_EQ(5, s.fib(5));
}

TEST_F(FibonacciNumberTest, 6) {
  EXPECT_EQ(8, s.fib(6));
}