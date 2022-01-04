class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        map<string, int> subtract = {
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}};

        int result = 0;
        int i = 0;
        int j = 0;
        while ( i < s.length()) {
            switch (s[i])
            {
            case 'I':
            case 'X':
            case 'C':
                j = i + 1;
                if (j < s.length())
                {
                    string sub = s.substr(i, 2);
                    
                    auto key = subtract.find(sub);
                    if (key != subtract.end()) {
                        //find it
                        result += subtract[sub];
                        i = j + 1;
                    } else {
                        result += m[s[i]];
                        i++;
                    }
                } else {
                    result += m[s[i]];
                    i++;
                }

                break;

            default:
                result += m[s[i]];
                i++;
                break;
            }
        }

        return result;
    }
};