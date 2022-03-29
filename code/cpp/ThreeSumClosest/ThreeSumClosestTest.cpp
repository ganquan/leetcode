#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "ThreeSumClosest.cpp"

using namespace std;

// Constraints:

// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

class ThreeSumClosestTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

TEST_F(ThreeSumClosestTest, Example1) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = 2;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}
TEST_F(ThreeSumClosestTest, Example2) {
    vector<int> nums = {0,0,0};
    int target = 1;
    int result = 0;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}

TEST_F(ThreeSumClosestTest, zerotest1) {

    vector<int> nums = {0,0,0};
    int target = 0;
    int result = 0;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}
TEST_F(ThreeSumClosestTest, zerotest2) {

    vector<int> nums = {0,0,0,0,0};
    int target = -100;
    int result = 0;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}

TEST_F(ThreeSumClosestTest, negativetestcase1) {

    vector<int> nums = {-1,-2,-3,-4,-5};
    int target = 0;
    int result = -6;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}
TEST_F(ThreeSumClosestTest, negativetestcase2) {

    vector<int> nums = {-1,-2,-3,-10,-5};
    int target = -11;
    int result = -10;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}

TEST_F(ThreeSumClosestTest, positivetestcase1) {

    vector<int> nums = {1,2,3,10,5};
    int target = 11;
    int result = 10;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}

TEST_F(ThreeSumClosestTest, positivetestcase2) {
    vector<int> nums = {1,2,3,10,5};
    int target = 9;
    int result = 9;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}

TEST_F(ThreeSumClosestTest, normaltestcase1) {

    vector<int> nums = {-7, -6, -4, 0, 1, 2, 4};
    int target = 0;
    int result = 0;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}

TEST_F(ThreeSumClosestTest, normaltestcase2) {

    vector<int> nums = {-7, -6, -4, 0, 1, 2, 4};
    int target = -16;
    int result = -17;

    EXPECT_EQ(result, s.threeSumClosest(nums, target));
}