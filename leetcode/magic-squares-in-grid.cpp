// 840. Magic Squares In Grid
// https://leetcode.com/problems/magic-squares-in-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Check Unique Properties of Magic Square
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        for (int row = 0; row + 2 < rows; ++row) {
            for (int col = 0; col + 2 < cols; ++col) {
                if (is_magic (grid, row, col))
                    ++ans;
            }
        }
        return ans;
    }

private:
    string sequence = "2943816729438167";
    string reversed = "7618349276183492";
    vector<int> border_indexes = {0, 1, 2, 5, 8, 7, 6, 3};
    bool is_magic (vector<vector<int>>& grid, int row, int col) {
        string border = "";
        for (int i : border_indexes) {
            int num = grid[row + i / 3][col + (i % 3)];
            border += to_string (num);
        }
        return  (grid[row][col] % 2 == 0 && 
                grid[row + 1][col + 1] == 5 && 
                (sequence.find(border) != string::npos ||
                reversed.find(border) != string::npos));
    }
};
