// 2466. Count Ways To Build Good Strings
// https://leetcode.com/problems/count-ways-to-build-good-strings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming (Iterative).
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        dp.resize(high + 1);
        dp[0] = 1;

        for (int right = 1; right <= high; ++right) {
            if (right >= zero)
                dp[right] += dp[right - zero];
            if (right >= one)
                dp[right] += dp[right - one];
            dp[right] %= MOD;
        }

        int ans = 0;
        for (int i = low; i <= high; ++i) {
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }

private:
    int MOD = 1e9 + 7;
    vector<int> dp;
};
