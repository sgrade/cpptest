// 2901. Longest Unequal Adjacent Groups Subsequence II
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = groups.size();
        dp.resize(n, 1), prev.resize(n, -1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && dp[j] + 1 > dp[i] && conditionsMet(words[i], words[j])) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_idx])
                max_idx = i;
        }

        vector<string> ans;
        for (int i = max_idx; i >= 0; i = prev[i])
            ans.emplace_back(words[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    int n, max_idx = 0;
    vector<int> dp, prev;
    bool conditionsMet(const string& s1, const string& s2) {
        if (s1.size() != s2.size())
            return false;
        int d = 0;
        for (int i = 0; i < s1.size(); ++i) {
            d += s1[i] != s2[i];
            if (d > 1)
                return false;
        }
        return d == 1; // Hamming distance must be exactly 1
    }
};
