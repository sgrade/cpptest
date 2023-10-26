// 823. Binary Trees With Factors
// https://leetcode.com/problems/binary-trees-with-factors/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #1: Dynamic Programming
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long> dp(n, 1);

        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i)
            idx[arr[i]] = i;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (idx.find(right) != idx.end())
                        dp[i] = (dp[i] + dp[j] * dp[idx[right]]) % MOD;
                }
            }
        }

        long ans = 0;
        for (const long& x: dp)
            ans += x;
        return (int) (ans % MOD);
    }
private:
    int MOD = 1e9 + 7;
    int n;
};
