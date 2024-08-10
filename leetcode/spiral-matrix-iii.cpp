// 885. Spiral Matrix III
// https://leetcode.com/problems/spiral-matrix-iii/

// Based on Editorial's Approach 1: Simulation
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cells = rows * cols;
        vector<vector<int>> ans;
        vector<vector<int>> directions{
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        int r = rStart, c = cStart;
        for (int step = 1, direction = 0; ans.size() < cells;) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                        ans.emplace_back(vector<int>{r, c});
                    r += directions[direction][0];
                    c += directions[direction][1];
                }
                direction = (direction + 1) % 4;
            }
            ++step;
        }
        return ans;
    }
};
