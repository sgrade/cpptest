// 837. New 21 Game
// https://leetcode.com/problems/new-21-game/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming
// TLE
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - k + 1; j <= min(i, maxPts); ++j) {
                dp[i] += dp[i - j] / maxPts;
            }
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};
