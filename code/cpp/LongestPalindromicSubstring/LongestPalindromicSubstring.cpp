class Solution {
public:
    string longestPalindrome(string s) {

        string result;
        int start = 0;
        int end = 0;
        int len = 0;

        for(int i = 0; i < s.size(); i++) {
            int s1 = palindrome(s, i, i);
            int s2 = palindrome(s, i, i + 1);

            len = max(s1, s2);
            if (len > end - start) {
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }


        int offset = end - start + 1;

        result = s.substr(start, offset);

        return result;
    }

    int palindrome(string s, int l, int r) {
        int left = l;
        int right = r;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left -= 1;
            right += 1;
        }

       return right - left - 1; 
    }
};