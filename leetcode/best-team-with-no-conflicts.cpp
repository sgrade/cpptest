// 1626. Best Team With No Conflicts
// https://leetcode.com/problems/best-team-with-no-conflicts/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 2: Bottom-Up Dynamic Programming
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i].first = ages[i], v[i].second = scores[i];
        }
        sort(v.begin(), v.end());

        vector<int> dp(n);
        dp[0] = v[0].second;
        int ans = v[0].second;
        for (int i = 1; i < n; ++i) {
            dp[i] = v[i].second;
            for (int j = 0; j < i; ++j) {
                if (v[i].second >= v[j].second)
                    dp[i] = max(dp[i], dp[j] + v[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
