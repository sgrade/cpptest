// 2787. Ways to Express an Integer as Sum of Powers
// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/

#include <cstdint>
#include <vector>
#include <cmath>

// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    int numberOfWays(int n, int x) {
        constexpr int kMod = 1e9 + 7;
        std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int64_t cur = pow(i, x);
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= cur) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - cur]) % kMod;
                }
            }
        }
        return dp[n][n];
    }
};
