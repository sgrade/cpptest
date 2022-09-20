// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        vector<string> current_ans;
        dfs(s, 0, current_ans, dp);
        return ans;
    }
    
    void dfs(string &s, int left, vector<string> &current_ans, vector<vector<bool>> &dp) {
        if (left >= s.size()) {
            ans.emplace_back(current_ans);
        }
        for (int right = left; right < s.size(); ++right) {
            if (s[left] == s[right] && (right - left < 3 || dp[left + 1][right - 1])) {
                dp[left][right] = true;
                current_ans.emplace_back(s.substr(left, right - left + 1));
                dfs(s, right + 1, current_ans, dp);
                current_ans.pop_back();
            }
        }
    }
        
private:
    vector<vector<string>> ans;
};
