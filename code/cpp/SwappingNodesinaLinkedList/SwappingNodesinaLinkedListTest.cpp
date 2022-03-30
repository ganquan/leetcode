#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SwappingNodesinaLinkedList.cpp"
#include "./../utils/utils.cpp"

using namespace std;

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 105
// 0 <= Node.val <= 100


class SwappingNodesinaLinkedListTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

//example testcase
TEST_F(SwappingNodesinaLinkedListTest, example1) {

    vector<int> input = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> expect = {1, 4, 3, 2, 5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, example2) {

    vector<int> input = {7,9,6,6,7,8,3,0,9,5};
    int k = 5;
    vector<int> expect = {7,9,6,6,8,7,3,0,9,5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

// input boundary testcase
TEST_F(SwappingNodesinaLinkedListTest, inputboundary1) {

    vector<int> input = {1};
    int k = 1;
    vector<int> expect = {1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, inputboundary2) {

    vector<int> input = {1, 2};
    int k = 1;
    vector<int> expect = {2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, inputboundary3) {

    vector<int> input = {1, 2};
    int k = 2;
    vector<int> expect = {2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, inputboundary4) {

    vector<int> input = {1, 2, 3};
    int k = 1;
    vector<int> expect = {3, 2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, inputboundary5) {

    vector<int> input = {1, 2, 3};
    int k = 2;
    vector<int> expect = {1, 2, 3};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, inputboundary6) {

    vector<int> input = {1, 2, 3};
    int k = 3;
    vector<int> expect = {3, 2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}


TEST_F(SwappingNodesinaLinkedListTest, evenElements1) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 3;
    vector<int> expect = {1, 2, 4, 3, 5, 6};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, evenElements2) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 4;
    vector<int> expect = {1, 2, 4, 3, 5, 6};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, evenElements3) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 5;
    vector<int> expect = {1, 5, 4, 3, 2, 6};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, evenElements4) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 6;
    vector<int> expect = {6, 2, 3, 4, 5, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}


TEST_F(SwappingNodesinaLinkedListTest, oddElements1) {

    vector<int> input = {1, 2, 3, 4, 5};
    int k = 3;
    vector<int> expect = {1, 2, 3, 4, 5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(SwappingNodesinaLinkedListTest, oddElements1) {

    vector<int> input = {1, 2, 3, 4, 5};
    int k = 5;
    vector<int> expect = {5, 2, 3, 4, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.swapNodes(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}