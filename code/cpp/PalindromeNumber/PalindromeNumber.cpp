#include <cstring>

// 11510 / 11510 test cases passed.
// Status: Accepted
// Runtime: 8 ms
// Memory Usage: 7.5 MB

// 内存用量还可以再优化下

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        const int ARRAY_LEN = 10;
        int *array = new int[ARRAY_LEN];
        int *array_copy = new int[ARRAY_LEN];
        memset(array, -1, sizeof(int)*ARRAY_LEN);
        memset(array_copy, -1, sizeof(int)*ARRAY_LEN);
        int index = 0;
        int temp = x;

        do {
            int x = temp % 10;
            array[index] = x;
            temp /= 10;
            index++;
        } while (temp != 0);

        for (int i = 0, j = index - 1; 
        i < index && j >= 0;
         i++, j--) {
            array_copy[i] = array[j];
        }

        int equal = memcmp(array, array_copy, sizeof(int)*ARRAY_LEN);

        return 0 == equal;
    }
};