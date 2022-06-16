// 139. Word Break
// https://leetcode.com/problems/word-break/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int right = 1; right <= n; ++right) {
            for (int left = 0; left < right; ++left) {
                if (dp[left] && 
                    words.find(s.substr(left, right - left)) != words.end()) {
                    dp[right] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
