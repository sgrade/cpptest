// 3195. Find the Minimum Area to Cover All Ones I
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int top_r = rows, bot_r = 0;
        int left_c = cols, right_c = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    continue;
                }
                top_r = min(top_r, r);
                bot_r = max(bot_r, r);
                left_c = min(left_c, c);
                right_c = max(right_c, c);
            }
        }
        int ans = (bot_r - top_r + 1) * (right_c - left_c + 1);
        return ans;
    }
};
