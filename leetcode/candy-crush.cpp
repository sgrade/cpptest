// 723. Candy Crush
// https://leetcode.com/problems/candy-crush/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: In-place Modification
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        rows = board.size(), cols = board[0].size();
        while (FindToDrop(board))
            Drop(board);
        return board;
    }

private:
    int rows, cols;

    bool FindToDrop(vector<vector<int>>& board) {
        bool need_to_drop = false;

        for (int row = 1; row < rows - 1; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 0)
                    continue;
                if (abs(board[row][col]) == abs(board[row - 1][col]) && abs(board[row][col]) == abs(board[row + 1][col])) {
                    board[row][col] = -(abs(board[row][col]));
                    board[row - 1][col] = -(abs(board[row][col]));
                    board[row + 1][col] = -(abs(board[row][col]));
                    need_to_drop = true;
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 1; col < cols - 1; ++col) {
                if (board[row][col] == 0)
                    continue;
                if (abs(board[row][col]) == abs(board[row][col - 1]) && abs(board[row][col]) == abs(board[row][col + 1])) {
                    board[row][col] = -(abs(board[row][col]));
                    board[row][col - 1] = -(abs(board[row][col]));
                    board[row][col + 1] = -(abs(board[row][col]));
                    need_to_drop = true;
                }
            }
        }

        // Crush
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] < 0)
                    board[row][col] = 0;
            }
        }

        return need_to_drop;
    }

    void Drop(vector<vector<int>>& board) {
        for (int col = 0; col < cols; ++col) {
            int lowest_row_with_zero = -1;
            for (int row = rows - 1; row >= 0; --row) {
                if (board[row][col] == 0)
                    lowest_row_with_zero = max(lowest_row_with_zero, row);
                else if (lowest_row_with_zero >= 0) {
                    swap(board[row][col], board[lowest_row_with_zero][col]);
                    --lowest_row_with_zero;
                }
            }
        }
    }
};
