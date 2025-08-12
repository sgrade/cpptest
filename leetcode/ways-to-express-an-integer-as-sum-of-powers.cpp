// 2787. Ways to Express an Integer as Sum of Powers
// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/

#include <cstdint>
#include <vector>
#include <cmath>

// Based on Editorial's Approach: Dynamic Programming; Space Optimization
class Solution {
public:
    int numberOfWays(int n, int x) {
        constexpr int kMod = 1e9 + 7;
        std::vector<int64_t> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int64_t cur = pow(i, x);
            if (cur > n)
                break;
            for (int j = n; j >= cur; --j) {
                dp[j] = (dp[j] + dp[j - cur]) % kMod;
            }
        }
        return dp[n];
    }
};

