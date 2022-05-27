// Success
// Details 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
// Memory Usage: 5.8 MB, less than 74.11% of C++ online submissions for Number of Steps to Reduce a Number to Zero.

class Solution {
public:
    int numberOfSteps(int num) {
        int step = 0;
        while (num != 0) {
            if (num & 0x1) {
                num = num & 0xFFFFFFFE;
            } else {
                num = num >> 1;
            }
            
            step++;
        }
        
        return step;
    }
};