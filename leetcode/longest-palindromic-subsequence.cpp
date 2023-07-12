// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursive Dynamic Programming
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        return check(s, 0, n - 1, dp);
    }

private:
    int check(string& s, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != 0)
            return dp[i][j];
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        
        if (s[i] == s[j])
            dp[i][j] = check(s, i + 1, j - 1, dp) + 2;
        else
            dp[i][j] = max(
                check(s, i + 1, j, dp),
                check(s, i, j - 1, dp)
            );
        return dp[i][j];
    }
};
