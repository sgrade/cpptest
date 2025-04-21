// 2145. Count the Hidden Sequences
// https://leetcode.com/problems/count-the-hidden-sequences/

#include <bits/stdc++.h>

using namespace std;


// Optimized with the Editorial
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int cur = lower, mn = lower, mx = lower, max_diff = upper - lower;
            for (const int& d: differences) {
                cur += d;
                mn = min(mn, cur);
                mx = max(mx, cur);
                if (mx - mn > max_diff)
                    return 0;
            }

            return max_diff - (mx - mn) + 1;
        }
    };
