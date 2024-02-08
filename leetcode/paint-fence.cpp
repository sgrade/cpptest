// 276. Paint Fence
// https://leetcode.com/problems/paint-fence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bottom-Up Dynamic Programming (Tabulation)
class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp(max(n + 1, 3));
        dp[1] = k, dp[2] = k * k;
        for (int i = 3; i <= n; ++i)
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
        return dp[n];
    }
};
