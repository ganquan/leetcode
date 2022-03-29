#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_distance = INT_MAX;
        int closest = target;

        if (nums.size() <= 2) {
            return closest;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int distance = max(sum, target) - min(sum, target);

                if (distance < closest_distance) {
                    closest_distance = distance;
                    closest = sum;
                }

                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    return target;
                }
            }
        }

        return closest;
    }
};