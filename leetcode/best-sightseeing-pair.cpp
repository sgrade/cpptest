// 1014. Best Sightseeing Pair
// https://leetcode.com/problems/best-sightseeing-pair/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Space-Optimized DP
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        int left = values[0];
        for (int i = 1; i < values.size(); ++i) {
            int right = values[i] - i;
            ans = max(ans, left + right);
            int current_left = values[i] + i;
            left = max(left, current_left);
        }
        return ans;
    }
};
