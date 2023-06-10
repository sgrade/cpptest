// 1626. Best Team With No Conflicts
// https://leetcode.com/problems/best-team-with-no-conflicts/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i].first = ages[i], v[i].second = scores[i];
        }
        sort(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return FindMaxScore(dp, v, -1, 0, n);
    }

    int FindMaxScore(vector<vector<int>>& dp, const vector<pair<int, int>>& v, int prev, int idx, const int& n) {
        if (idx >= n)
            return 0;
        if (dp[prev + 1][idx] != -1)
            return dp[prev + 1][idx];
        
        if (prev == -1 || v[idx].second >= v[prev].second) {
            return dp[prev + 1][idx] = max (
                FindMaxScore(dp, v, prev, idx + 1, n), 
                 v[idx].second + FindMaxScore(dp, v, idx, idx + 1, n)
            );
        }

        return dp[prev + 1][idx] = FindMaxScore(dp, v, prev, idx + 1, n);
    }
};
