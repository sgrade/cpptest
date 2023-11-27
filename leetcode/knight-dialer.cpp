// 935. Knight Dialer
// https://leetcode.com/problems/knight-dialer/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int knightDialer(int n) {
        this->n = n;
        memo.resize(n + 1, vector<int>(10));;
        int ans = 0;
        for (int digit = 0; digit < 10; ++digit)
            ans = (ans + dp(n - 1, digit)) % MOD;
        return ans;
    }

private:
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
    vector<vector<int>> memo;
    int dp(int remain, int digit) {
        if (remain == 0)
            return 1;
        if (memo[remain][digit] != 0)
            return memo[remain][digit];
        int ans = 0;
        for (const int& next_digit: jumps[digit])
            ans = (ans + dp(remain - 1, next_digit)) % MOD;
        memo[remain][digit] = ans;
        return ans;
    }
};
