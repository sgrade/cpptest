// 2145. Count the Hidden Sequences
// https://leetcode.com/problems/count-the-hidden-sequences/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long cur = lower, mn = lower, mx = lower;
            for (const int& d: differences) {
                cur += d;
                mn = min(mn, cur);
                mx = max(mx, cur);
            }

            int ans = 1;
            if (mn < lower)
                ans -= lower - mn;
            if (mx > upper)
                ans -= mx - upper;
            else
                ans += upper - mx;
            return max(0, ans);
        }
    };
