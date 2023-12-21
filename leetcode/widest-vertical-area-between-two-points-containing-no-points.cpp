// 1637. Widest Vertical Area Between Two Points Containing No Points
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int left, right, ans = 0;
        for (int i = 1; i < n; ++i) {
            right = points[i][0], left = points[i - 1][0];
            ans = max(ans, right - left);
        }
        return ans;
    }
};
