// 289. Game of Life
// https://leetcode.com/problems/game-of-life/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        cols = board[0].size();
        int cnt;
        vector<vector<int>> ans(rows, vector<int>(cols));
        ans = board;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cnt = CountNeighbors(i, j, board);
                if (cnt < 2 || cnt > 3) {
                    ans[i][j] = 0;
                }
                else if (board[i][j] == 1 && (cnt == 2 || cnt == 3)) {
                    ans[i][j] = board[i][j];
                }
                else if (board[i][j] == 0 && cnt == 3) {
                    ans[i][j] = 1;
                }
            }
        }
        board = ans;
    }
    
private:
    int rows, cols;
    
    int CountNeighbors(const int &row, const int &col, vector<vector<int>> &board) {
        int cnt = 0;
        if (row > 0 && board[row-1][col] == 1) {
            ++cnt;
        }
        if (col > 0 && board[row][col-1] == 1) {
            ++cnt;
        }
        if (row < rows-1 && board[row+1][col] == 1) {
            ++cnt;
        }
        if (col < cols-1 && board[row][col+1] == 1) {
            ++cnt;
        }
        if ((row > 0 && col > 0) && board[row-1][col-1] == 1) {
            ++cnt;
        }
        if ((row < rows-1 && col < cols-1) && board[row+1][col+1] == 1) {
            ++cnt;
        }
        if ((row > 0 && col < cols-1) && board[row-1][col+1] == 1) {
            ++cnt;
        }
        if ((row < rows-1 && col > 0) && board[row+1][col-1] == 1) {
            ++cnt;
        }
        
        return cnt;
    }
};
