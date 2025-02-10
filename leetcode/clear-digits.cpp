// 3174. Clear Digits
// https://leetcode.com/problems/clear-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int i = s.size() - 1, digits = 0;
        while (i >= 0) {
            if (!isdigit(s[i])) {
                if (digits > 0)
                    --digits;
                else
                    ans += s[i];
            }
            else
                ++digits;
            --i;

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
