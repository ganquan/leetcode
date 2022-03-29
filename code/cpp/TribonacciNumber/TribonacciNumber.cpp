#include <cstring>
using namespace std;

class Solution {
 public:
    int tribonacci(int n) {
        int *p = new int[n + 5];
        memset(p, 0, (n + 5) * sizeof(int));
        p[0] = 0;
        p[1] = 1;
        p[2] = 1;

        for (int i = 3; i <= n; i++) {
            p[i] = p[i - 1] + p[i - 2] + p[i - 3];
        }
        return p[n];
    }
};