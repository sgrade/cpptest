// 1043. Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        this->k = k;
        dp.resize(n, -1);
        return maxSum(arr, 0);
    }
private:
    vector<int> dp;
    int k;
    int maxSum(vector<int>& arr, int start) {
        int n = arr.size();
        if (start >= n)
            return 0;
        if (dp[start] != -1)
            return dp[start];
        
        int cur_max = 0, ans = 0;
        int end = min(n, start + k);
        for (int i = start; i < end; ++i) {
            cur_max = max(cur_max, arr[i]);
            ans = max(ans, cur_max * (i - start + 1) + maxSum(arr, i + 1));
        }
        return dp[start] = ans;
    }
};
