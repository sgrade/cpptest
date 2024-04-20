// 1992. Find All Groups of Farmland
// https://leetcode.com/problems/find-all-groups-of-farmland/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Greedy
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int rows = land.size(), cols = land[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (land[row][col] == 1) {
                    int r, c;
                    for (r = row; r < rows && land[r][col] == 1; ++r) {
                        for (c = col; c < cols && land[r][c] == 1; ++c)
                            land[r][c] = 0;
                    }
                    ans.push_back({row, col, r - 1, c - 1});
                }
            }
        }
        return ans;
    }
};
