// 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size(), n2 = text2.size();
        n = max(n1, n2);
        int ans = dfs(text1, text2, 0, 0, 0);
        return ans;
    }
private:
    int n1, n2, n;
    vector<int> dp;
    int dfs (const string& text1, const string& text2, int i1, int i2, int ans) {
        if (i1 == n1 || i2 == n2)
            return ans;
        int pick1_pick2 = 0;
        if (text1[i1] == text2[i2])
            pick1_pick2 = dfs(text1, text2, i1 + 1, i2 + 1, ans + 1);
        int pick1_skip2 = dfs(text1, text2, i1, i2 + 1, ans);
        int skip1_pick2 = dfs(text1, text2, i1 + 1, i2, ans);
        int skip1_skip2 = dfs(text1, text2, i1 + 1, i2 + 1, ans);
        ans = max({pick1_pick2, pick1_skip2, skip1_pick2, skip1_skip2});
        return ans;
    }
};
