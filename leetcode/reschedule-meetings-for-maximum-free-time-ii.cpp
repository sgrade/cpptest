// 3440. Reschedule Meetings for Maximum Free Time II
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = startTime.size(), 
        prev_gap = 0, 
        left_gap = startTime[0], 
        ans = 0, 
        right_gap, event_duration, cur_ans;

        // left to right
        for (int i = 0; i < n; ++i) {
            event_duration = endTime[i] - startTime[i], 
            right_gap = i < n - 1 ? startTime[i + 1] - endTime[i] : eventTime - endTime[i], 
            cur_ans = left_gap + right_gap;
            if (event_duration <= prev_gap)
                cur_ans += event_duration;
            ans = max(ans, cur_ans);
            prev_gap = max(prev_gap, left_gap);
            left_gap = right_gap;
        }

        // right to left
        prev_gap = 0;
        right_gap = eventTime - endTime[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            event_duration = endTime[i] - startTime[i];
            left_gap = i > 0 ? startTime[i] - endTime[i - 1] : startTime[i];
            cur_ans = left_gap + right_gap;
            if (event_duration <= prev_gap)
                cur_ans += event_duration;
            ans = max(ans, cur_ans);
            prev_gap = max(prev_gap, right_gap);
            right_gap = left_gap;
        }

        return ans;
    }
};
