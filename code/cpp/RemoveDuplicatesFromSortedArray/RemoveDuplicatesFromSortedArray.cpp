#include <vector>

using namespace std;

class Solution {
public:

   int removeDuplicates(vector<int>& nums) {
       vector<int>::iterator ptr;
       vector<int> tmp;

       for(ptr = nums.begin(); ptr < nums.end() - 1; ptr++) {
           if (*ptr == *(ptr + 1)) {
               continue;
           } else {
               tmp.push_back(*ptr);
           }
       }

       tmp.push_back(*(ptr));
       for (auto i = 0; i < tmp.size(); i++) {
           nums[i] = tmp[i];
       }

       return tmp.size();
    }
};