// 529. Minesweeper
// https://leetcode.com/problems/minesweeper/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        rows = board.size();
        cols = board[0].size();
        visited.resize(rows, vector<bool>(cols));

        dfs(board, click[0], click[1]);
        return board;
    }

private:
    int rows, cols;
    
    // 0 - not visited, 1 - visited, 2 - mine
    vector<vector<bool>> visited;

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row == rows || col < 0 || col == cols || visited[row][col]) 
            return;

        visited[row][col] = true;

        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return;
        }

        int adjacent_mines = 0;
        adjacent_mines += (row - 1 >= 0) && board[row - 1][col] == 'M';
        adjacent_mines += (row + 1 < rows) && board[row + 1][col] == 'M';
        adjacent_mines += (col - 1 >= 0) && board[row][col - 1] == 'M';
        adjacent_mines += (col + 1 < cols) && board[row][col + 1] == 'M';
        adjacent_mines += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] == 'M';
        adjacent_mines += row - 1 >= 0 && col + 1 < cols && board[row - 1][col + 1] == 'M';
        adjacent_mines += row + 1 < rows && col - 1 >= 0 &&  board[row + 1][col - 1] == 'M';
        adjacent_mines += row + 1 < rows && col + 1 < cols && board[row + 1][col + 1] == 'M';

        if (adjacent_mines != 0) {
            board[row][col] = adjacent_mines + '0';
            return;
        }

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
        dfs(board, row - 1, col - 1);
        dfs(board, row + 1, col - 1);
        dfs(board, row - 1, col + 1);
        dfs(board, row + 1, col + 1);
        board[row][col] = 'B';

        return;
    }
};
