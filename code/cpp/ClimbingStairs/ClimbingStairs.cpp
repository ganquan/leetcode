#include <cstring>
using namespace std;

class Solution {
public:
   int climbStairs(int n) {
       int *p = new int[n+5];
       memset(p, 0, (n+5)*sizeof(int));
       p[1] = 1;
       p[2] = 2;
       for (int i = 3; i <= n; i++) {
           p[i] = p[i - 1] + p[i - 2];
       }
       return p[n];
   }
};