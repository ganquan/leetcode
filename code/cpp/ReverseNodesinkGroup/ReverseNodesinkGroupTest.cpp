#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ReverseNodesinkGroup.cpp"
#include "./../utils/utils.cpp"

using namespace std;

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000


class ReverseNodesinkGroupTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

//example testcase
TEST_F(ReverseNodesinkGroupTest, example1) {

    vector<int> input = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> expect = {2, 1, 4, 3, 5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, example2) {

    vector<int> input = {1,2,3,4,5};
    int k = 3;
    vector<int> expect = {3,2,1,4,5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}


// input boundary testcase
TEST_F(ReverseNodesinkGroupTest, inputboundary1) {

    vector<int> input = {1};
    int k = 1;
    vector<int> expect = {1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary2) {

    vector<int> input = {1, 2};
    int k = 1;
    vector<int> expect = {1, 2};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary3) {

    vector<int> input = {1, 2};
    int k = 2;
    vector<int> expect = {2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary4) {

    vector<int> input = {1, 2, 3};
    int k = 1;
    vector<int> expect = {1, 2, 3};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary41) {

    vector<int> input = {1, 2, 3};
    int k = 2;
    vector<int> expect = {2, 1, 3};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary5) {

    vector<int> input = {1, 2, 3};
    int k = 3;
    vector<int> expect = {3, 2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary6) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 1;
    vector<int> expect = {1, 2, 3, 4, 5, 6};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary7) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 2;
    vector<int> expect = {2, 1, 4, 3, 6, 5};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary8) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 3;
    vector<int> expect = {3, 2, 1, 6, 5, 4};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary9) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 4;
    vector<int> expect = {4, 3, 2, 1, 5, 6};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseNodesinkGroupTest, inputboundary10) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 5;
    vector<int> expect = {5, 4, 3, 2, 1, 6};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}


TEST_F(ReverseNodesinkGroupTest, inputboundary11) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    int k = 6;
    vector<int> expect = {6, 5, 4, 3, 2, 1};

    ListNode* head = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseKGroup(head, k));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}