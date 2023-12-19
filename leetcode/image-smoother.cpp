// 661. Image Smoother
// https://leetcode.com/problems/image-smoother/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size(), cols = img[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int current = img[row][col];
                int cnt = 1;
                for (const auto& [r_diff, c_diff]: directions) {
                    int current_row = row + r_diff;
                    int current_col = col + c_diff;
                    if (current_row < 0 || current_row == rows || current_col < 0 || current_col == cols)
                        continue;
                    current += img[current_row][current_col];
                    ++cnt;
                }
                ans[row][col] = current / cnt;
            }
        }
        return ans;
    }
private:
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
};
