
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        set<vector<int>> s;

        if (nums.size() <= 2) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) {
                //reduce steps by step over same value
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                if(0 == nums[i] +  nums[j] + nums[k]) {
                    //find it
                    s.insert({nums[i], nums[j++], nums[k--]});
                } else if(nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }

        }

        for(auto i:s) {
            result.push_back(i);
        }

        return result;

    }
};