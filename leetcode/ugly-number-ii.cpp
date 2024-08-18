// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Editorial's Approach 3: Dynamic Programming (DP)
class Solution {
public:
    int nthUglyNumber(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int t2 = 0, t3 = 0, t5 = 0;
        int t2_by_2 = 2, t3_by_3 = 3, t5_by_5 = 5;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = min({t2_by_2, t3_by_3, t5_by_5});
            if (dp[i] == t2_by_2) {
                ++t2;
                t2_by_2 = dp[t2] * 2;
            }
            if (dp[i] == t3_by_3) {
                ++t3;
                t3_by_3 = dp[t3] * 3;
            }
            if (dp[i] == t5_by_5) {
                ++t5;
                t5_by_5 = dp[t5] * 5;
            }
        }
        return dp.back();
    }
};
