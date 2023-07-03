// 1035. Uncrossed Lines
// https://leetcode.com/problems/uncrossed-lines/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Iterative Dynamic Programming
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for (int idx1 = 1; idx1 <= n1; ++idx1) {
            for (int idx2 = 1; idx2 <= n2; ++idx2) {
                if (nums1[idx1 - 1] == nums2[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                    dp[idx1][idx2] = max(
                        dp[idx1][idx2 - 1],
                        dp[idx1 - 1][idx2]
                    );
            }
        }

        return dp[n1][n2];
    }
};
