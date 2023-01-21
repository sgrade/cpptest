// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> counter_s(26), counter_t(26);
        for (const char& ch: s) {
            ++counter_s[ch - 'a'];
        }
        for (const char&ch : t) {
            ++counter_t[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (counter_s[i] != counter_t[i]) {
                return i + 'a';
            }
        }
        return '0';
    }
};
