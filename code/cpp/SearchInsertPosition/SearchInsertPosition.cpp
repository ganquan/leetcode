#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;

        while(lower <= upper) {
            int mid = (lower + upper) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        
        return upper + 1;
    }
};