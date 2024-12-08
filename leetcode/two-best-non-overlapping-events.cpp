// 2054. Two Best Non-Overlapping Events
// https://leetcode.com/problems/two-best-non-overlapping-events/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Greedy
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<tuple<int, int, int>> times;
        for (const vector<int>& e: events) {
            times.emplace_back(e[0], 1, e[2]);      // 0 for start time
            times.emplace_back(e[1] + 1, 0, e[2]);  // 1 for end time
        }
        sort(times.begin(), times.end());
        int ans = 0, mx = 0;
        for (const auto[time, type, value]: times) {
            if (type == 1)
                ans = max(ans, value + mx);
            else
                mx = max(mx, value);
        }
        return ans;
    }
};
