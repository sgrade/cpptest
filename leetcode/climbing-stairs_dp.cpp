// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(45);
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i < n; ++i)
            dp[i] = dp[i - 2] + dp[i - 1];
        return dp[n - 1];
    }
};
