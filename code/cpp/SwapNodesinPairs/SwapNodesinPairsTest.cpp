#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SwapNodesinPairs.cpp"
#include "./../utils/utils.cpp"

using namespace std;

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

class SwapNodesinPairsTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

TEST_F(SwapNodesinPairsTest, example1) {

    vector<int> input = {1, 2, 3, 4};
    vector<int> expect = {2, 1, 4, 3};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwapNodesinPairsTest, example2) {

    vector<int> input = {};
    vector<int> expect = {};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}



TEST_F(SwapNodesinPairsTest, example3) {

    vector<int> input = {1};
    vector<int> expect = {1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}


TEST_F(SwapNodesinPairsTest, evenElements1) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    vector<int> expect = {2, 1, 4, 3, 6, 5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwapNodesinPairsTest, evenElements2) {

    vector<int> input = {1, 2};
    vector<int> expect = {2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwapNodesinPairsTest, oddElements1) {

    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> expect = {2, 1, 4, 3, 5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwapNodesinPairsTest, oddElements2) {

    vector<int> input = {1, 2, 3};
    vector<int> expect = {2, 1, 3};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapPairs(head));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}