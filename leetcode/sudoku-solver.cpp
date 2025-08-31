// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> b(9, vector<int>(9, -1));
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    b[row][col] = board[row][col] - '0';
                }
            }
        }
        Backtrack(0, 0, b);
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                board[row][col] = b[row][col] + '0';
            }
        }
    }

private:
    bool CanPlace(int num, int row, int col, vector<vector<int>>& b) {
        for (int c = 0; c < 9; ++c) {
            if (b[row][c] == num) return false;
        }
        for (int r = 0; r < 9; ++r) {
            if (b[r][col] == num) return false;
        }
        int start_r = (row / 3) * 3, start_c = (col / 3) * 3;
        for (int r = start_r; r < start_r + 3; ++r) {
            for (int c = start_c; c < start_c + 3; ++c) {
                if (b[r][c] == num) return false;
            }
        }
        return true;
    }

    bool Backtrack(int row, int col, vector<vector<int>>& b) {
        for (int r = row; r < 9; ++r) {
            for (int c = (r == row ? col : 0); c < 9; ++c) {
                if (b[r][c] == -1) {
                    for (int num = 1; num <= 9; ++num) {
                        if (CanPlace(num, r, c, b)) {
                            b[r][c] = num;
                            if (Backtrack(r, c + 1, b)) return true;
                            b[r][c] = -1;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
