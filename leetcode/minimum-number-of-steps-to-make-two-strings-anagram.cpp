// 1347. Minimum Number of Steps to Make Two Strings Anagram
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt_s(26), cnt_t(26);
        for (const char& ch: s)
            ++cnt_s[ch - 'a'];
        for (const char& ch: t)
            ++cnt_t[ch - 'a'];
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt_t[i] > cnt_s[i])
                ans += cnt_t[i] - cnt_s[i];
        }
        return ans;
    }
};
