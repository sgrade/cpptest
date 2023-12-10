// 2237. Count Positions on Street With Required Brightness
// https://leetcode.com/problems/count-positions-on-street-with-required-brightness/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> left, right;
        for (const vector<int>& v: lights) {
            left.emplace_back(v[0] - v[1]);
            right.emplace_back(v[0] + v[1]);
        }
        sort (left.begin(), left.end());
        sort (right.begin(), right.end());
        int ans = 0;
        int lamps = 0;
        int lidx = 0, ridx = 0;
        for (int i = 0; i < n; ++i) {
            while (lidx < left.size() && left[lidx] <= i) {
                ++lamps;
                ++lidx;
            }
            while (ridx < right.size() && right[ridx] < i) {
                --lamps;
                ++ridx;
            }
            ans += lamps >= requirement[i] ? 1 : 0;
        }
        return ans;
    }
};
