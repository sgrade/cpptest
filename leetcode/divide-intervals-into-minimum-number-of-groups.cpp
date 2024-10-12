// 2406. Divide Intervals Into Minimum Number of Groups
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

#include <bits/stdc++.h>

using namespace std;


// Based on the Meeting Rooms II solution - https://leetcode.com/problems/meeting-rooms-ii/
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        multiset<int> start, end;
        for (const vector<int>& i: intervals) {
            start.emplace(i[0]);
            end.emplace(i[1]);
        }

        int ans = 0, current_ans = 0;
        while (!start.empty() && !end.empty()) {
            if (*start.begin() <= *end.begin()) {
                ++current_ans;
                start.erase(start.begin());
            }
            else {
                --current_ans;
                end.erase(end.begin());
            }
            ans = max (ans, current_ans);
        }
        return ans;
    }
};
