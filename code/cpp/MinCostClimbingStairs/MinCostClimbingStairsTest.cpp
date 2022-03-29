#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "MinCostClimbingStairs.cpp"


using namespace std;

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

class MinCostClimbingStairsTest : public ::testing::Test {
 protected:
  void SetUp() override {
      s = Solution();
  }

  // void TearDown() override {}
  Solution s;
};

TEST_F(MinCostClimbingStairsTest, testcase1) {
    vector<int> input = {10, 15, 20};
    EXPECT_EQ(15, s.minCostClimbingStairs(input));
}

TEST_F(MinCostClimbingStairsTest, testcase2) {
    vector<int> input = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(6, s.minCostClimbingStairs(input));
}