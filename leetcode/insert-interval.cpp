// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0 || newInterval[0] > intervals.back()[1]) {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        
        
        int left = newInterval[0], right = newInterval[1];
        
        vector<vector<int>>::iterator start_it, end_it;
        
        end_it = find_if(intervals.begin(), intervals.end(), [right](const vector<int> &v){
            return v[1] >= right;
        });
        
        if (end_it != intervals.end()) {
            start_it = end_it;
            if (right >= (*end_it)[0]) {
                right = (*end_it)[1];
                ++end_it;
            }
        }
        else {
            start_it = intervals.begin() + intervals.size() - 1;
        }
        
        while (start_it != intervals.begin() && (*start_it)[0] > left) {
            --start_it;
        }
        
        if (left > (*start_it)[1]) {
            ++start_it;
        }
        else {
            left = min(left, (*start_it)[0]);
        }
        
        int pos = distance(intervals.begin(), start_it);
        intervals.erase(start_it, end_it);

        intervals.insert(intervals.begin() + pos, vector<int>{left, right});
        
        return intervals;
    }
};
