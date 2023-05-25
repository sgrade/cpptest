// 837. New 21 Game
// https://leetcode.com/problems/new-21-game/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1);
        dp[0] = 1;
        double sum = k > 0 ? 1 : 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = sum / maxPts;
            if (i < k)
                sum += dp[i];
            if (i - maxPts >= 0 && i - maxPts < k)
                sum -= dp[i - maxPts];
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};
