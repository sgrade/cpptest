// 1861. Rotating the Box
// https://leetcode.com/problems/rotating-the-box/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rows = box.size(), cols = box[0].size();
        for (int r = 0; r < rows; ++r) {
            int min_c = cols;
            for (int c = cols - 1; c >= 0; --c) {
                if (box[r][c] == '*')
                    min_c = c;
                else if (box[r][c] == '#') {
                    box[r][c] = '.';
                    box[r][min_c - 1] = '#';
                    min_c = min_c - 1;
                }
            }
        }

        vector<vector<char>> ans(cols, vector<char>(rows));
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                char cur = box[row][col];
                int r = col;
                int c = rows - row - 1;
                ans[r][c] = cur;
            }
        }
        return ans;
    }
};
