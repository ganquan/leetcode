#include <stdint.h>

#include <cmath>
#include <string>
#include <vector>

using namespace std;

// after 6 error submits, see the combined testcase.
// finally accepted.
//
// Runtime: 3 ms, faster than 77.70% of C++ online submissions for String to
// Integer (atoi). Memory Usage: 7.1 MB, less than 12.97% of C++ online
// submissions for String to Integer (atoi).

class Solution {
 public:
    int myAtoi(string s) {
        long _pow[11] = {
            1,       10,       100,       1000,       10000,       100000,
            1000000, 10000000, 100000000, 1000000000, 10000000000,
        };
        long result = 0;
        bool isPositive = true;
        bool sign_met = false;
        bool leading_zero_met = false;
        vector<char> v = vector<char>();
        const char *str = s.c_str();

        // leading characters.
        for (int i = 0; i < s.length(); i++) {
            // leading space
            if (v.size() == 0 && str[i] == ' ' && !sign_met &&
                !leading_zero_met) {
                continue;
            }

            // sign
            if (v.size() == 0 && str[i] == '-' && !sign_met &&
                !leading_zero_met) {
                isPositive = false;
                sign_met = true;
                continue;
            }

            if (v.size() == 0 && str[i] == '+' && !sign_met &&
                !leading_zero_met) {
                sign_met = true;
                continue;
            }

            // leading zero
            if (v.size() == 0 && str[i] == '0') {
                leading_zero_met = true;
                continue;
            }

            if (str[i] >= '0' && str[i] <= '9') {
                v.push_back(str[i]);
            } else {
                break;
            }
        }

        // now convert vector to int
        if (0 == v.size()) {
            return result;
        }

        for (int i = v.size() - 1, j = 0; i >= 0; i--, j++) {
            result += long(int(v[i] - '0') * _pow[j]);

            if (j == 10) {
                // exceed int32_max or int32_min
                if (isPositive) {
                    result = INT32_MAX;
                } else {
                    result = INT32_MIN;
                    isPositive = true;  //后面不处理符号了
                }

                break;
            }
        }

        //+- sign.
        if (!isPositive) {
            result *= -1;
        }

        // boundary
        if (result > INT32_MAX) {
            result = INT32_MAX;
        }

        if (result < INT32_MIN) {
            result = INT32_MIN;
        }

        return (int)result;
    }
};