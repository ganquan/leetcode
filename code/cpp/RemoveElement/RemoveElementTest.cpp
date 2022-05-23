#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "RemoveElement.cpp"

using namespace std;

// Constraints:

// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100

class RemoveElementTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

// example testcase
TEST_F(RemoveElementTest, example1) {
    // Input: nums = [3,2,2,3], val = 3
    // Output: 2, nums = [2,2,_,_]
    // Explanation: Your function should return k = 2, with the first two
    // elements of nums being 2. It does not matter what you leave beyond the
    // returned k (hence they are underscores).

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    vector<int> expect = {2, 2};

    auto k = s.removeElement(nums, val);

    EXPECT_EQ(k, expect.size());

    sort(nums.begin(), nums.begin() + k);
    for (int i = 0; i < k; i++) {
        EXPECT_EQ(nums[i], expect[i]);
    }
}

TEST_F(RemoveElementTest, example2) {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    vector<int> expect = {0, 0, 1, 3, 4};

    auto k = s.removeElement(nums, val);

    EXPECT_EQ(k, expect.size());

    sort(nums.begin(), nums.begin() + k);
    for (int i = 0; i < k; i++) {
        EXPECT_EQ(nums[i], expect[i]);
    }
}

//empty input
TEST_F(RemoveElementTest, input1) {
    vector<int> nums = {};
    int val = 0;
    vector<int> expect = {};

    auto k = s.removeElement(nums, val);

    EXPECT_EQ(k, expect.size());

    sort(nums.begin(), nums.begin() + k);
    for (int i = 0; i < k; i++) {
        EXPECT_EQ(nums[i], expect[i]);
    }
}

//val not exist
TEST_F(RemoveElementTest, input2) {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 5};
    int val = 6;
    vector<int> expect = {1, 1, 2, 2, 3, 4, 5};

    auto k = s.removeElement(nums, val);

    EXPECT_EQ(k, expect.size());

    sort(nums.begin(), nums.begin() + k);
    for (int i = 0; i < k; i++) {
        EXPECT_EQ(nums[i], expect[i]);
    }
}

// match and clear
TEST_F(RemoveElementTest, input3) {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
    int val = 1;
    vector<int> expect = {};

    auto k = s.removeElement(nums, val);

    EXPECT_EQ(k, expect.size());

    sort(nums.begin(), nums.begin() + k);
    for (int i = 0; i < k; i++) {
        EXPECT_EQ(nums[i], expect[i]);
    }
}