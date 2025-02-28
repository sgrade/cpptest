// 1092. Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Most Optimal - Space Optimized Dynamic Programming
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n1 = str1.size(), n2 = str2.size();
            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
            for (int i1 = 0; i1 <= n1; ++i1)
                dp[i1][0] = i1;
            for (int i2 = 0; i2 <= n2; ++i2)
                dp[0][i2] = i2;
            for (int i1 = 1; i1 <= n1; ++i1) {
                for (int i2 = 1; i2 <= n2; ++i2) {
                    if (str1[i1 - 1] == str2[i2 - 1])
                        dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
                    else
                        dp[i1][i2] = min(dp[i1 - 1][i2], dp[i1][i2 - 1]) + 1;
                }
            }

            string supersequence = "";
            int i1 = n1, i2 = n2;
            while (i1 > 0 && i2 > 0) {
                if (str1[i1 - 1] == str2[i2 - 1]) {
                    supersequence += str1[i1 - 1];
                    --i1;
                    --i2;
                }
                else if (dp[i1 - 1][i2] < dp[i1][i2 - 1]) {
                    supersequence += str1[i1 - 1];
                    --i1;
                }
                else {
                    supersequence += str2[i2 - 1];
                    --i2;
                }
            }

            while (i1 > 0) {
                supersequence += str1[i1 - 1];
                --i1;
            }
            while (i2 > 0) {
                supersequence += str2[i2 - 1];
                --i2;
            }

            reverse(supersequence.begin(), supersequence.end());
            return supersequence;
        }
    };
