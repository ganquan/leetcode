#include <cmath>

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        unsigned long absn = abs(n);
        while (absn) {
            if (absn & 0x1)
                result *= x;
            
            absn >>= 1;
            x *= x;
       }
       
       return n >=0? result: 1/result;
    }
};