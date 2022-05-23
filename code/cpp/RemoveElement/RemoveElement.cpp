#include <vector>

using namespace std;

class Solution {
 public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> tmp;

        for (auto ptr = nums.begin(); ptr < nums.end(); ptr++) {
            if (*ptr == val) {
                continue;
            } else {
                tmp.push_back(*ptr);
            }
        }

        for (auto i = 0; i < tmp.size(); i++) {
            nums[i] = tmp[i];
        }

        return tmp.size();
    }
};