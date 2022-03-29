#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> p(n, INT_MAX);
        p[0] = cost[0];
        p[1] = cost[1];

        for (int i = 2; i < n; i++) {
            
            p[i] = min(p[i - 1], p[i - 2]) + cost[i];
        }

        return min(p[cost.size() - 1], p[cost.size() - 2]);
    }
};

