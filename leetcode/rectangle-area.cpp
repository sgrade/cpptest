// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area_a = (ax2 - ax1) * (ay2 - ay1);
        int area_b = (bx2 - bx1) * (by2 - by1);
        int ans = area_a + area_b;

        if (ax2 <= bx1 || bx2 <= ax1 || ay2 <= by1 || by2 <= ay1) {
            return ans;
        }

        // Diffs
        int dx = min(ax2, bx2) - max(ax1, bx1);
        int dy = min(ay2, by2) - max(ay1, by1);
        int area_d = dx * dy;

        return ans - area_d;
    }
};
