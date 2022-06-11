// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; ++i) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int ans = 0;
        
        int idx_s = 0, idx_e = 0;
        
        for (idx_s = 0; idx_s < n; ++idx_s) {
            if (end[idx_e] <= start[idx_s]) ++idx_e;
            else ++ans;
        }
        
        return ans;
    }
};


int main() {

    return 0;
}