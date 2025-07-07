// 1353. Maximum Number of Events That Can Be Attended
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Greedy
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0, n = events.size(), max_day = 0;
        for (const vector<int>& event: events)
            max_day = max(max_day, event[1]);

        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq;
        for (int day = 1, event = 0; day <= max_day; ++day) {
            while (event < n && events[event][0] <= day) {
                pq.emplace(events[event][1]);
                ++event;
            }
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            if (!pq.empty()) {
                pq.pop();
                ++ans;
            }
        }
        
        return ans;
    }
};
