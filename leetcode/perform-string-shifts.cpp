// 1427. Perform String Shifts
// https://leetcode.com/problems/perform-string-shifts/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Compute Net Shift
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left_shifts = 0;
        for (const vector<int>& v: shift) {
            if (v[0] == 0)
                left_shifts += v[1];
            else
                left_shifts -= v[1];
        }
        left_shifts %= (int)s.size();
        if (left_shifts > 0)
            rotate(s.begin(), s.begin() + left_shifts, s.end());
        else
            rotate(s.rbegin(), s.rbegin() - left_shifts, s.rend());
        return s;
    }
};
