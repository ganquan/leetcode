#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ReverseLinkedList.cpp"
#include "./../utils/utils.cpp"

using namespace std;




class ReverseLinkedListTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

//example testcase
TEST_F(ReverseLinkedListTest, example1) {

    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> expect = {5, 4, 3, 2, 1};

    ListNode* start = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseList(start));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}




// input boundary testcase
TEST_F(ReverseLinkedListTest, inputboundary1) {

    vector<int> input = {1};
    vector<int> expect = {1};

    ListNode* start = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseList(start));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseLinkedListTest, inputboundary2) {

    vector<int> input = {1, 2};
    vector<int> expect = {2, 1};

    ListNode* start = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseList(start));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}


TEST_F(ReverseLinkedListTest, inputboundary4) {

    vector<int> input = {1, 2, 3};
    vector<int> expect = {3, 2, 1};

    ListNode* start = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseList(start));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}

TEST_F(ReverseLinkedListTest, inputboundary6) {

    vector<int> input = {1, 2, 3, 4, 5, 6};
    vector<int> expect = {6, 5, 4, 3, 2, 1};

    ListNode* start = utils::listFromVector(input); 
    vector<int> output = utils::vectorFromList(s.reverseList(start));

    ASSERT_THAT(output, ::testing::ElementsAreArray(expect));
}
