// 957. Prison Cells After N Days
// https://leetcode.com/problems/prison-cells-after-n-days/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // Based on https://leetcode.com/problems/prison-cells-after-n-days/discuss/717519/C%2B%2B-Super-Easy-Solution-Explained100-Time-50-Space
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        while (n--) {
            for (int i = 1; i < 7; ++i) {
                tmp[i] = cells[i - 1] == cells[i + 1];
            }
            if (!seen.empty() && seen.front() == tmp) {
                return seen[n % seen.size()];
            }
            else {
                seen.push_back(tmp);
            }
            cells = tmp;
        }
        return cells;
    }
};
