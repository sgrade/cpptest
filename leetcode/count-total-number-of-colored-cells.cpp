// 2579. Count Total Number of Colored Cells
// https://leetcode.com/problems/count-total-number-of-colored-cells/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        long long coloredCells(int n) {
            long long ans = 1 + 4 * ((long long)(n - 1) * n / 2);
            return ans;
        }
    };
