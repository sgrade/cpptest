// 139. Word Break
// https://leetcode.com/problems/word-break/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Leetcode's Sample 0 ms submission
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.resize(n, -1);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return solve(s, 0, words);
    }
private:
    int n;
    vector<int> dp;
    bool solve(string& s, int i, unordered_set<string>& words) {
        if (i == n)
            return true;
        if (dp[i] != -1)
            return dp[i];
        string subs;
        for (int j = i; j < n; ++j) {
            subs += s[j];
            if (words.find(subs) != words.end() && solve(s, j + 1, words))
                return true;
        }
        return dp[i] = 0;
    }
};
