// 3174. Clear Digits
// https://leetcode.com/problems/clear-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int digits = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (isdigit(s[i]))
                ++digits;
            else {
                if (digits > 0)
                    --digits;
                else
                    ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
