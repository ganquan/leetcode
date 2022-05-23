#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "Pow.cpp"

using namespace std;
using ::testing::DoubleLE;

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// -104 <= xn <= 104

class PowTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Solution(); }

    // void TearDown() override {}
    Solution s;
};

// example testcase
TEST_F(PowTest, example1) {
    // Input: x = 2.00000, n = 10
    // Output: 1024.00000
    auto x = 2.00000;
    auto n = 10;
    auto expect = 1024.00000;

    EXPECT_PRED_FORMAT2(DoubleLE, s.myPow(x, n), expect);
}

TEST_F(PowTest, example2) {
    // Input: x = 2.10000, n = 3
    // Output: 9.26100
    auto x = 2.10000;
    auto n = 3;
    auto expect = 9.26100;

    EXPECT_PRED_FORMAT2(DoubleLE, s.myPow(x, n), expect);
}

TEST_F(PowTest, example3) {
    // Input: x = 2.00000, n = -2
    // Output: 0.25000
    // Explanation: 2-2 = 1/22 = 1/4 = 0.25
    auto x = 2.00000;
    auto n = -2;
    auto expect = 0.25000;

    EXPECT_PRED_FORMAT2(DoubleLE, s.myPow(x, n), expect);
}

// zero input
TEST_F(PowTest, input1) {
    auto x = 2.00000;
    auto n = 0;
    auto expect = 1.00000;

    EXPECT_PRED_FORMAT2(DoubleLE, s.myPow(x, n), expect);
}

TEST_F(PowTest, input2) {
    auto x = 2.00000;
    auto n = 1;
    auto expect = 2.00000;

    EXPECT_PRED_FORMAT2(DoubleLE, s.myPow(x, n), expect);
}

TEST_F(PowTest, input3) {
    auto x = 2.00000;
    auto n = -1;
    auto expect = 0.50000;

    EXPECT_PRED_FORMAT2(DoubleLE, s.myPow(x, n), expect);
}