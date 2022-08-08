#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "SearchInsertPosition.cpp"

using namespace std;

// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums contains distinct values sorted in ascending order.
// -10^4 <= target <= 10^4

class SearchInsertPositionTest : public ::testing::Test {
 protected:
    void SetUp() override { sln = Solution(); }

    // void TearDown() override {}
    Solution sln;
};

// example testcase
TEST_F(SearchInsertPositionTest, example1) {
    vector<int> input = {1,3,5,6};
    int target = 5;
    int expect = 2;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, example2) {
    vector<int> input = {1,3,5,6};
    int target = 2;
    int expect = 1;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, example3) {
    vector<int> input = {1,3,5,6};
    int target = 7;
    int expect = 4;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}


TEST_F(SearchInsertPositionTest, border1) {
    vector<int> input = {};
    int target = 7;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, border2) {
    vector<int> input = {0};
    int target = 7;
    int expect = 1;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, border3) {
    vector<int> input = {0};
    int target = -3;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t21) {
    vector<int> input = {1,5};
    int target = -3;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t22) {
    vector<int> input = {1,5};
    int target = 9;
    int expect = 2;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t23) {
    vector<int> input = {1,5};
    int target = 3;
    int expect = 1;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t24) {
    vector<int> input = {1,5};
    int target = 1;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t25) {
    vector<int> input = {1,5};
    int target = 5;
    int expect = 1;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}


TEST_F(SearchInsertPositionTest, t31) {
    vector<int> input = {1,5,9};
    int target = -3;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t32) {
    vector<int> input = {1,5,9};
    int target = 4;
    int expect = 1;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t33) {
    vector<int> input = {1,5,9};
    int target = -4;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t34) {
    vector<int> input = {1,5,9};
    int target = 10;
    int expect = 3;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t35) {
    vector<int> input = {1,5,9};
    int target = 7;
    int expect = 2;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t36) {
    vector<int> input = {1,5,9};
    int target = 9;
    int expect = 2;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t37) {
    vector<int> input = {1,5,9};
    int target = 5;
    int expect = 1;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}

TEST_F(SearchInsertPositionTest, t38) {
    vector<int> input = {1,5,9};
    int target = 1;
    int expect = 0;

    EXPECT_EQ(sln.searchInsert(input, target), expect);
}