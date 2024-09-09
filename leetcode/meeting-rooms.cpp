// 252. Meeting Rooms
// https://leetcode.com/problems/meeting-rooms/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (intervals.size() > 1) {
            sort(intervals.begin(), intervals.end());
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i][0] < intervals[i - 1][1])
                    return false;
            }
        }
        return true;
    }
};
