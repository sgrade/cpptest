// 2900. Longest Unequal Adjacent Groups Subsequence I
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans{words[0]};
        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != groups[i - 1])
                ans.emplace_back(words[i]);
        }
        return ans;
    }
};
