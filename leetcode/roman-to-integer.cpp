// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) {
                string candidate = s.substr(i, 2);
                if (strings.find(candidate) != strings.end()) {
                    ans += strings[candidate];
                    ++i;
                    continue;
                }
            }
            ans += chars[s[i]];
        }
        return ans;
    }

private:
    map<string, int> strings {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900}
    };
    map<char, int> chars {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
};
