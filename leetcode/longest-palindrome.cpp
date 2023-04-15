// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        for (const char& ch: s)
            ++counter[ch];
        int ans = 0, odd = 0;
        for (const auto& [_, cnt]: counter) {
            if (cnt % 2 == 0) {
                ans += cnt;
            }
            else {
                ans += cnt / 2 * 2;
                ++odd;
            }
        }
        if (odd > 0) 
            ++ans;
        return ans;
    }

private:
    map<char, int> counter;
};
