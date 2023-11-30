// 624. Maximum Distance in Arrays
// https://leetcode.com/problems/maximum-distance-in-arrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #3 Single Scan
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = arrays[0][0];
        int mx = arrays[0][arrays[0].size() - 1];
        int ans = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            vector<int>& v = arrays[i];
            int x1 = abs(v.back() - mn);
            int x2 = abs(mx - v.front());
            ans = max(ans, max(x1, x2));
            mn = min(mn, v.front());
            mx = max(mx, v.back());
        }
        return ans;
    }
};
