// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Binary Search. Modified with iterators (slow runtime, but memory efficient).
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (intervals.empty())
            return {newInterval};
        int n = intervals.size(), start = newInterval[0], left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (intervals[mid][0] < start)
                left = mid + 1;
            else
                right = mid - 1;
        }
        intervals.insert(intervals.begin() + left, newInterval);

        vector<vector<int>>::iterator prev = intervals.begin(), cur = intervals.begin() + 1;
        while (cur != intervals.end()) {
            if ((*prev)[1] < (*cur)[0]) {
                ++prev;
                ++cur;
            }
            else {
                (*prev)[1] = max((*prev)[1], (*cur)[1]);
                intervals.erase(cur);
            }
        }
        return intervals;
    }
};
