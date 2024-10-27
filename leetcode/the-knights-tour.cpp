// 2664. The Knight’s Tour
// https://leetcode.com/problems/the-knights-tour/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Backtracking
class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        rows = m, cols = n, total_moves = rows * cols;
        board.resize(rows, vector<int>(cols));
        board[r][c] = -1;
        Backtrack(r, c, 1);
        board[r][c] = 0;
        return board;
    }

private:
    int rows, cols, total_moves;
    vector<vector<int>> board;
    
    bool Backtrack(int row, int col, int moves) {
        if (moves == total_moves)
            return true;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!IsMoveValid (row, col, r, c))
                    continue;
                board[r][c] = moves;
                if (Backtrack(r, c, moves + 1))
                    return true;
                board[r][c] = 0;
            }
        }
        return false;
    }

    bool IsMoveValid (int from_row, int from_col, int to_row, int to_col) {
        return 
            to_row >= 0 && to_col >= 0 && to_row < rows && to_col < cols &&
            min(abs(from_row - to_row), abs(from_col - to_col)) == 1 &&
            max(abs(from_row - to_row), abs(from_col - to_col)) == 2 && 
            board[to_row][to_col] == 0;
    }
};
