#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "ContainerWithMostWater.cpp"

using namespace std;

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104

class ContainerWithMostWaterTest : public ::testing::Test {
 protected:
    void SetUp() override { sln = Solution(); }

    // void TearDown() override {}
    Solution sln;
};

// example testcase
TEST_F(ContainerWithMostWaterTest, example1) {
    vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int expect = 49;

    EXPECT_EQ(sln.maxArea(input), expect);
}

TEST_F(ContainerWithMostWaterTest, example2) {
    vector<int> input = {1,1};
    int expect = 1;

    EXPECT_EQ(sln.maxArea(input), expect);
}

//
TEST_F(ContainerWithMostWaterTest, input1) {
    vector<int> input = {1,1};
    int expect = 1;

    EXPECT_EQ(sln.maxArea(input), expect);
}

//wrong answer case
//29 / 60 test cases passed.
TEST_F(ContainerWithMostWaterTest, wrong1) {
    vector<int> input = {1,2,1};
    int expect = 2;
    //wrong answer = 1
    EXPECT_EQ(sln.maxArea(input), expect);
}
