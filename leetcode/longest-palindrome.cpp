// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<char, int> counter;
        for (const char& ch: s)
            ++counter[ch];
        int ans = 0;
        for (const auto& [_, cnt]: counter) {
            if (cnt % 2 == 0)
                ans += cnt;
            else
                ans += cnt -1;
        }
        if (s.size() > ans) 
            ++ans;
        return ans;
    }
};
