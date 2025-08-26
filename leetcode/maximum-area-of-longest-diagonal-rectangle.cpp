// 3000. Maximum Area of Longest Diagonal Rectangle
// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/

#include <vector>
#include <algorithm>

using std::vector;
using std::max;


class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double max_diag = 0;
        int max_area = 0;
        for (const vector<int>& d : dimensions) {
            double diag_squared = d[0] * d[0] + d[1] * d[1];
            if (diag_squared > max_diag) {
                max_diag = diag_squared;
                max_area = d[0] * d[1];
            }
            else if (diag_squared == max_diag) {
                max_area = max(max_area, d[0] * d[1]);
            }
        }
        return max_area;
    }
};
