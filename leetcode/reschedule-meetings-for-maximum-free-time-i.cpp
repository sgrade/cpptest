// 3439. Reschedule Meetings for Maximum Free Time I
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Greedy + Sliding Window
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = startTime.size(), ans = 0;
        int t = 0;      // Duration of the merged interval;
        for (int i = 0; i < n; ++i) {
            t += endTime[i] - startTime[i];
            
            // Boundaries of the merged FREE time interval
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            ans = max(ans, right - left - t);

            if (i >= k - 1) // The leftmost event is not in the sliding window anymore
                t -= endTime[i - k + 1] - startTime[i - k + 1];
        }
        
        return ans;
    }
};
