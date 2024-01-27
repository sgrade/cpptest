// 629. K Inverse Pairs Array
// https://leetcode.com/problems/k-inverse-pairs-array/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded
// Based on Editorial's Approach 2: Using Recursion with Memoization
class Solution {
public:
    int kInversePairs(int n, int k) {
        memo.resize(1001, vector<int>(1001));
        return getPairs(n, k); 
    }
private:
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;
    int getPairs (int n, int k) {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (memo[n][k] != 0)
            return memo[n][k];
        int ans = 0;
        for (int i = 0; i <= min(k, n - 1); ++i)
            ans = (ans + getPairs(n - 1, k - i)) % MOD;
        memo[n][k] = ans;
        return ans;
    }
};
