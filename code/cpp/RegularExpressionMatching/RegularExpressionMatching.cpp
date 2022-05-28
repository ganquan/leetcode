#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    // Good explain of Memoization Dynamic Programming
    // https://www.youtube.com/watch?v=HAA8mgxlov8
    //
    // reference:
    // https://leetcode.com/problems/regular-expression-matching/discuss/5684/c-on-space-dp
    // example code missing the index guard for j - 2
    // so add the line: if (j >= 2) before the decision branch start
   bool isMatch(string s, string p) {
       int s_index = 0;
       int p_index = 0;
       vector<vector<bool>> cache(s.size() + 1,
                                  vector<bool>(p.size() + 1, false));
       cache[0][0] = true;

       for (int i = 0; i <= s.size(); i++) {
           for (int j = 1; j <= p.size(); j++) {
               if (p[j - 1] == '*') {
                   if (j >= 2) {
                       cache[i][j] = cache[i][j - 2] ||                                 /* decision branch 1: '*' matches 0 times, if pattern before '*' matched, now should also match */
                                  (i && cache[i - 1][j] &&                              /* decision branch 2:, '*' matches at least 1 times, char after '*' matched the s[i - 1] */
                                   (s[i - 1] == p[j - 2] || p[j - 2] == '.'));          /* and pattern before '*' is same char or the pattern is '.' */ 
                   }
               } else {
                   cache[i][j] =
                       i                                                    /* make sure [i - 1] within bound */
                       && cache[i - 1][j - 1]                               /* if p[j] match s[i], then p[j - 1] should match s[i - 1] */
                       && (s[i - 1] == p[j - 1] || p[j - 1] == '.');        /* p[j - 1] match s[i - 1]: same char or the pattern is '.' */
               }
           }
       }

       return cache[s.size()][p.size()];
   }
};