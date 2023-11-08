// 2849. Determine if a Cell Is Reachable at a Given Time
// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Math
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(fx - sx), dy = abs(fy - sy);
        if (dx == 0 && dy == 0 && t == 1)
            return false;
        return t >= max(dx, dy);
    }
};
