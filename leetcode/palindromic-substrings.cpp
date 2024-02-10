// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #1: Check All Substrings
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int left = 0; left < s.size(); ++left)
            for (int right = left; right < s.size(); ++right) {
                ans += isPalindrome(s, left, right);
            }
        return ans;
    }
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};
