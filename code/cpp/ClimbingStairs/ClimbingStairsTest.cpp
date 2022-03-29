#include <gtest/gtest.h>
#include <string>
#include "ClimbingStairs.cpp"


using namespace std;

// Constraints:
// 1 <= n <= 45


class ClimbingStairsTest : public ::testing::Test {
 protected:
  void SetUp() override {
      s = Solution();
  }

  // void TearDown() override {}
  Solution s;
};

TEST_F(ClimbingStairsTest, 1) {
  EXPECT_EQ(1, s.climbStairs(1));
}

TEST_F(ClimbingStairsTest, 2) {
  EXPECT_EQ(2, s.climbStairs(2));
}

TEST_F(ClimbingStairsTest, 3) {
  EXPECT_EQ(3, s.climbStairs(3));
}

TEST_F(ClimbingStairsTest, 4) {
  EXPECT_EQ(5, s.climbStairs(4));
}

TEST_F(ClimbingStairsTest, 5) {
  EXPECT_EQ(8, s.climbStairs(5));
}