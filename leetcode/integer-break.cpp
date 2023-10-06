// 343. Integer Break
// https://leetcode.com/problems/integer-break/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        memo.resize(n + 1);
        return dp(n);
    }
private:
    vector<int> memo;
    int dp(int num) {
        if (num <= 3)
            return num;
        if (memo[num] != 0)
            return memo[num];
        int ans = num;
        for (int i = 2; i < num; ++i)
            ans = max(ans, i * dp(num - i));
        memo[num] = ans;
        return ans;
    }
};
