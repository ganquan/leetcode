class Solution {
public:
    // Runtime Memory Language
    // 23 ms	8.5 MB	cpp
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxLen = 1;
        int lastRepeatPos = -1;
        for (int i = 0; i < s.size(); i++) {

            if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }

            if (i - lastRepeatPos > maxLen) {
                maxLen = i - lastRepeatPos;
            }

            m[s[i]] = i;
        }

        return maxLen;
    }

    //不用map性能升天
    // Runtime Memory Language
    // 6 ms	6.9 MB	cpp
    int lengthOfLongestSubstring(string s) {
        const int MAX_CHARS = 256;
        int m[MAX_CHARS];
        memset(m, -1, sizeof(m));

        int maxLen = 0;
        int lastRepeatPos = -1;
        for (int i = 0; i < s.size(); i++) {

            if (m[s[i]] != -1 && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }

            if (i - lastRepeatPos > maxLen) {
                maxLen = i - lastRepeatPos;
            }

            m[s[i]] = i;
        }

        return maxLen;
    }
};