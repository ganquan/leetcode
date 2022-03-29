#include <cstring>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int *p = new int[n + 2];
        memset(p, 0, (n + 2) * sizeof(int));
        p[0] = 0;
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            p[i] = p[i - 1] + p[i - 2];
       }
       return p[n]; 
    }
};