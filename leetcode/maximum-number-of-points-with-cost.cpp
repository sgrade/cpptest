// 1937. Maximum Number of Points with Cost
// https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Dynamic Programming (Optimized)
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        rows = points.size(), cols = points[0].size();
        vector<long long> cur(cols), prev(cols);
        for (const vector<int>& row: points) {
            long long mx = 0;
            for (int col = 0; col < cols; ++col) {
                mx = max (mx - 1, prev[col]);
                cur[col] = mx;
            }
            mx = 0;
            for (int col = cols - 1; col >= 0; --col) {
                mx = max (mx - 1, prev[col]);
                cur[col] = max(cur[col], mx) + row[col];
            }
            prev = cur;
        }
        return *max_element(prev.begin(), prev.end());
    }

private:
    int rows, cols;
};
