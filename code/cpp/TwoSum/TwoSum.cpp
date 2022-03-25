class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m = {};
        map<int, int>::iterator it;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            
            int distance = target - nums[i];
            it = m.find(distance);
            
            if (it != m.end()) {
                result.push_back(it->second);
                result.push_back(i);
                
                return result;
            } else {
                
                m[nums[i]] = i;
                continue;
            }
        }
        
        return result;
    }
};