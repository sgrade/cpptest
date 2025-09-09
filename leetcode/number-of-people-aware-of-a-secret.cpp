// 2327. Number of People Aware of a Secret
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#include <vector>
using std::vector;


class Solution {
public:
    int PeopleAwareOfSecret(int n, int delay, int forget) {
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int day = 2; day <= n; ++day) {
            for (int prev = std::max(1, day - forget + 1); prev <= day - delay; ++prev) {
                dp[day] = (dp[day] + dp[prev]) % kMod;
            }
        }
        int result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1) result = (result + dp[day]) % kMod;
        }
        return result;
    }
private:
    static constexpr int kMod = 1000000007;
};
