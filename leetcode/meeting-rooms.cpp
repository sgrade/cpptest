// 252. Meeting Rooms
// https://leetcode.com/problems/meeting-rooms/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() > 1) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
                return v1[0] < v2[0];
            });
            int mx = intervals[0][1];
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i][0] < mx) {
                    return false;
                }
                mx = intervals[i][1];
            }
        }
        return true;
    }
};
