// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int rows, cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // If already explored
                if (board[row][col] == 'E') {
                    continue;
                }
                
                bool captured = true;
                vector<pair<int, int>> current;
                explore(board, row, col, captured, current);
                char ch = captured ? 'X' : 'O';
                for (auto &[row, col]: current) {
                    board[row][col] = ch;
                }
            }
        }
    }
    
    void explore(vector<vector<char>>& board, int row, int col, bool &captured, vector<pair<int, int>> &current) {
        if (board[row][col] == 'X' || board[row][col] == 'E') {
            return;
        }
        board[row][col] = 'E';
        current.emplace_back(pair<int, int>(row, col));
        if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
            captured = false;
            return;
        }
        explore(board, row - 1, col, captured, current);
        explore(board, row + 1, col, captured, current);
        explore(board, row, col - 1, captured, current);
        explore(board, row, col + 1, captured, current);
    }
};
