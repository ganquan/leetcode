#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        const char *str = s.c_str();
        stack<char> stck = stack<char>();

        for (int i = 0; i < s.length(); i++) {
            if (isLeft(str[i])) {
                stck.push(str[i]);
            } else {
                if (!stck.empty() && isPair(stck.top(), str[i])) {
                    stck.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }

        return stck.empty();
    }

    bool isLeft(char c) {
        return (c == '(' || c == '[' || c == '{');
    }

    bool isPair(char left, char right) {
        switch (left) {
            case '(':
                return right == ')';
            case '[':
                return right == ']';
            case '{':
                return right == '}';

            default:
                return false;
        }
    }
};