#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "RemoveDuplicatesFromSortedArray.cpp"

using namespace std;

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.

class RemoveDuplicatesFromSortedArrayTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;

    void test(vector<int>& input, vector<int>& expect) {
        s.removeDuplicates(input);
        auto k = expect.size();

        for (int i = 0; i < k; i++) {
            EXPECT_EQ(input[i], expect[i]);
        }
    };
};

// example testcase
TEST_F(RemoveDuplicatesFromSortedArrayTest, example1) {
    vector<int> input = {1, 1, 2};
    vector<int> expect = {1, 2};

    test(input, expect);
}

TEST_F(RemoveDuplicatesFromSortedArrayTest, example2) {
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> expect = {0, 1, 2, 3, 4};

    test(input, expect);
}


//no duplicate
TEST_F(RemoveDuplicatesFromSortedArrayTest, input1) {
    vector<int> input = {0, 1, 2, 3 ,4};
    vector<int> expect = {0, 1, 2, 3, 4};

    test(input, expect);
}

// all dupulicate
TEST_F(RemoveDuplicatesFromSortedArrayTest, input2) {
    vector<int> input = {3, 3, 3, 3, 3};
    vector<int> expect = {3};

    test(input, expect);
}

TEST_F(RemoveDuplicatesFromSortedArrayTest, input3) {
    vector<int> input = {1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3};
    vector<int> expect = {1, 2, 3};

    test(input, expect);
}

TEST_F(RemoveDuplicatesFromSortedArrayTest, input4) {
    vector<int> input = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
    vector<int> expect = {1, 2, 3};

    test(input, expect);
}

TEST_F(RemoveDuplicatesFromSortedArrayTest, input5) {
    vector<int> input = {1};
    vector<int> expect = {1};

    test(input, expect);
}