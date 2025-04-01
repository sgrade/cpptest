// 2140. Solving Questions With Brainpower
// https://leetcode.com/problems/solving-questions-with-brainpower/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming (Iterative)
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = questions.size();
            vector<long> dp(n);
            dp[n - 1] = questions[n - 1][0];
            for (int i = n - 2; i >= 0; --i) {
                dp[i] = questions[i][0];
                int skip = questions[i][1];
                int j = i + skip + 1;
                if (j < n)
                    dp[i] += dp[j];
                dp[i] = max(dp[i], dp[i + 1]);
            }
            return dp[0];
        }
    };
