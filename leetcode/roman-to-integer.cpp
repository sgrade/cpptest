// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int current, prev = 0, ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'M') current = 1000;
            else if (s[i] == 'D') current = 500;
            else if (s[i] == 'C') current = 100;
            else if (s[i] == 'L') current = 50;
            else if (s[i] == 'X') current = 10;
            else if (s[i] == 'V') current = 5;
            else current = 1;
            if (current < prev) ans -= current;
            else ans += current;
            prev = current;
        }
        return ans;
    }
};
