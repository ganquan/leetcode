#include <vector>

using namespace std;

class Solution {
 public:
    //双指针思路是个聪明的解法
    //这里有算法动态图演示
    // https://www.geeksforgeeks.org/container-with-most-water/
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            if (area > max)
                max = area;

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max;
    }
};