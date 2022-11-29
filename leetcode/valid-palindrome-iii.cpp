// 1216. Valid Palindrome III
// https://leetcode.com/problems/valid-palindrome-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Top-Down DP (2D)
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return Check (s, 0, n - 1, dp) <= k;
    }
private:
    int Check (const string &s, int i, int j, vector<vector<int>> &dp) {
        if (i == j) {
            return 0;
        }
        if (i + 1 == j) {
            return s[i] != s[j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = Check(s, i + 1, j - 1, dp);
        }
        
        return dp[i][j] = 1 + min(Check(s, i + 1, j, dp), Check(s, i, j - 1, dp));
    }
};
