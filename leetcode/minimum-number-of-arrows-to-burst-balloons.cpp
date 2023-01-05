// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>

using namespace std;


// Some ideas are from Leetcode's Approach 1: Greedy
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });
        int ans = 1, right = points[0][1];
        for (const vector<int>& v: points) {
            if (v[0] > right) {
                ++ans;
                right = v[1];
            }
        }
        return ans;
    }
};
