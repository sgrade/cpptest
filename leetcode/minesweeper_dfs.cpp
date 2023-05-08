// 529. Minesweeper
// https://leetcode.com/problems/minesweeper/

#include <bits/stdc++.h>

using namespace std;


// Modified with ideas from Leetcode's Sample 7 ms submission
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        rows = board.size();
        cols = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };
    
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row == rows || col < 0 || col == cols || board[row][col] != 'E') 
            return;
        
        int adjacent_mines = count_mines(board, row, col);
        if (adjacent_mines != 0) {
            board[row][col] = adjacent_mines + '0';
            return;
        }

        board[row][col] = 'B';
        for (const auto& [r, c]: directions)
            dfs(board, row + r, col + c);
    }

    int count_mines (vector<vector<char>>& board, const int row, const int col) {
        int adjacent_mines = 0;
        for (const auto& [r, c]: directions) {
            int rr = row + r;
            int cc = col + c;
            if (rr < 0 || rr == rows || cc < 0 || cc == cols) 
                continue;
            adjacent_mines += board[rr][cc] == 'M';
        }
        return adjacent_mines;
    }
};
