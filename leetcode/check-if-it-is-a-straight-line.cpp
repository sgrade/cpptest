// 1232. Check If It Is a Straight Line
// https://leetcode.com/problems/check-if-it-is-a-straight-line/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 3) return true;
        bool ans = true;
        int dx, dy, ref_dx, ref_dy, ref_slope, slope;
        ref_dx = coordinates[1][0] - coordinates[0][0];
        ref_dy = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            dx = coordinates[i][0] - coordinates[i - 1][0];
            dy = coordinates[i][1] - coordinates[i - 1][1];
            // for the division to zero get a hint from Editorial's Approach: Slope Property
            // delta_y1 / delta_x1 = delta_y2 / delta_x2
            // the below formula is changed from the above to avoid division by zero
            if (ref_dx * dy != ref_dy * dx) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
