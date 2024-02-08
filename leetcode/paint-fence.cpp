// 276. Paint Fence
// https://leetcode.com/problems/paint-fence/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Top-Down Dynamic Programming (Recursion + Memoization)
class Solution {
public:
    int numWays(int n, int k) {
        dp.resize(n + 1, -1);
        return TotalWays(n, k);
    }

private:
    vector<int> dp;
    int TotalWays (int i, const int& k) {
        if (i == 1) return k;
        if (i == 2) return k * k;
        if (dp[i] != -1)
            return dp[i];
        dp[i] = (k - 1) * (TotalWays(i - 1, k) + TotalWays(i - 2, k));
        return dp[i];
    }
};
