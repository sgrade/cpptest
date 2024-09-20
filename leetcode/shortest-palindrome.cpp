// 214. Shortest Palindrome
// https://leetcode.com/problems/shortest-palindrome/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Two Pointer
class Solution {
public:
    string shortestPalindrome(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size();
        if (n == 0)
            return s;
        int left = 0;
        for (int right = n - 1; right >= 0; --right) {
            if (s[right] == s[left])
                ++left;
        }
        if (left == n)
            return s;

        string pal_candidate = s.substr(0, left);
        string non_pal_suffix = s.substr(left);
        string reverse_suffix(
            non_pal_suffix.rbegin(),
            non_pal_suffix.rend()
        );

        return  reverse_suffix +
                shortestPalindrome(pal_candidate) +
                non_pal_suffix;
    }
};
