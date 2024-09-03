// 1945. Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int getLucky(string s, int k) {
        string digits;
        for (const char& ch: s) {
            int num = ch - 'a' + 1;
            digits += to_string(num);
        }
        int ans;
        for (int i = 0; i < k; ++i) {
            ans = 0;
            for (const char& ch: digits)
                ans += ch - '0';
            digits = to_string(ans);
        }
        return ans;
    }
};
