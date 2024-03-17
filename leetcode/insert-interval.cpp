// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Binary Search
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

        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < n + 1; ++i) {
            if (ans.back()[1] < intervals[i][0])
                ans.emplace_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
};
