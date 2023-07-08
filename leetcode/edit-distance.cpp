// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Bottom-Up Dynamic Programming: Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 == 0)
            return n2;
        if (n2 == 0)
            return n1;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int idx1 = 1; idx1 <= n1; ++idx1) 
            dp[idx1][0] = idx1;
        for (int idx2 = 1; idx2 <= n2; ++idx2)
            dp[0][idx2] = idx2;
        
        for (int idx1 = 1; idx1 <= n1; ++idx1) {
            for (int idx2 = 1; idx2 <= n2; ++idx2) {
                if (word1[idx1 - 1] == word2[idx2 - 1])
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
                else {
                    dp[idx1][idx2] = min ({
                        dp[idx1 - 1][idx2],
                        dp[idx1][idx2 - 1],
                        dp[idx1 - 1][idx2 - 1]
                    }) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};
