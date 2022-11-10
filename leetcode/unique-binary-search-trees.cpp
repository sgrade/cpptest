// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/

#include <bits/stdc++.h>

using namespace std;

// Based on Leetcode's Approach 1: Dynamic Programming
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int root = 2; root <= n; ++root) {
            for (int left_child = 1; left_child <= root; ++left_child) {
                dp[root] += dp[left_child - 1] * dp[root - left_child];
            }
        }
        
        return dp[n];
    }
};
