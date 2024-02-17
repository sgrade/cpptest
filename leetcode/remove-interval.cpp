// 1272. Remove Interval
// https://leetcode.com/problems/remove-interval/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Sweep Line, One Pass.
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> ans;
        for (const vector<int>& i: intervals) {
            // no overlap
            if (i[0] > toBeRemoved[1] || i[1] < toBeRemoved[0])
                ans.emplace_back(i);
            else {
                if (i[0] < toBeRemoved[0])
                    ans.emplace_back(vector<int>{i[0], toBeRemoved[0]});
                if (i[1] > toBeRemoved[1])
                    ans.emplace_back(vector<int>{toBeRemoved[1], i[1]});
            }
        }
        return ans;
    }
};
