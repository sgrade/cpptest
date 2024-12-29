// 1639. Number of Ways to Form a Target String Given a Dictionary
// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-down Dynamic Programming
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = words[0].size();
        dp.resize(n, vector<int>(target.size(), -1)),
        freq.resize(n, vector<int>(26, 0));
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = words[i][j] - 'a';
                ++freq[j][idx];
            }
        }

        return getWords(words, target, 0, 0);
    }

private:
    int n;
    vector<vector<int>> dp, freq;
    int MOD = 1e9 + 7;

    long getWords(vector<string>& words, string& target, int words_idx, int target_idx) {
        if (target_idx == target.size())
            return 1;
        if (words_idx == n || n - words_idx < target.size() - target_idx)
            return 0;

        if (dp[words_idx][target_idx] != -1)
            return dp[words_idx][target_idx];

        long ways = 0;
        int pos = target[target_idx] - 'a';
        ways += getWords(words, target, words_idx + 1, target_idx);
        ways += freq[words_idx][pos] * getWords(words, target, words_idx + 1, target_idx + 1);
        return dp[words_idx][target_idx] = ways % MOD;
    }
};
