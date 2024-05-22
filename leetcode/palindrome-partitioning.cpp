// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Backtracking with Dynamic Programming
class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.resize(n, vector<bool>(n));
        vector<string> current;
        int left = 0, right = 0;
        dfs (s, 0, current);
        return ans;
    }
private:
    int n;
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    void dfs (const string& s, int left, vector<string>& current) {
        if (left >= n)
            ans.emplace_back(current);
        for (int right = left; right < n; ++right) {
            if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1])) {
                dp[left][right] = true;
                current.emplace_back(s.substr(left, right - left + 1));
                dfs(s, right + 1, current);
                current.pop_back();
            }
        }
    }
};
