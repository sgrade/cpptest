// 1025. Divisor Game
// https://leetcode.com/problems/divisor-game/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/divisor-game/solutions/323884/c-dp-100-time-complexity/
class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            for (int x = 1; x * x <= i; ++x) {
                if (i % x == 0 && !dp[i - x])
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};
