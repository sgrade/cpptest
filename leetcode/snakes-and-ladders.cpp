// 909. Snakes and Ladders
// https://leetcode.com/problems/snakes-and-ladders/

#include <bits/stdc++.h>

using namespace std;


// Solution works, but not correctly:
//  I thought I can do only one cell forward, but according to the task I can jump up to 6 steps forward.
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        rows = board.size();
        cols = board[0].size();
        int max_idx = rows * rows;

        vector<int> counter(max_idx + 1);
        vector<bool> dont_come_back(max_idx + 1);

        int moves = 0;
        int current_cell_idx = 1;
        while (current_cell_idx < max_idx) {
            move (board, counter, dont_come_back, current_cell_idx, moves);
        }

        return counter[rows * rows];
    }

private:
    int rows, cols;

    void move (const vector<vector<int>>& board, vector<int>& counter, vector<bool>& dont_come_back, int& current_cell_idx, int& moves) {
        moves = min(counter[current_cell_idx], moves) + 1;
        
        int rem = current_cell_idx % rows;
        int row = rows - (current_cell_idx - 1) / rows - 1;
        int col;
        if (row % 2 != rows % 2) {  // left to right
            col = rem == 0 ? cols - 1 : rem - 1;
        }
        else {                      // right to left
            col = rem == 0 ? 0 : cols - rem;
        }
              
        int jump_cell_idx = board[row][col] != -1 ? board[row][col] : current_cell_idx + 1;

        int next_cell_idx;
        if (jump_cell_idx < current_cell_idx && !dont_come_back[jump_cell_idx]) {
            next_cell_idx = jump_cell_idx;
            dont_come_back[jump_cell_idx] = true;
        }
        else {
            next_cell_idx = current_cell_idx + 1;
        }

        counter[jump_cell_idx] = counter[jump_cell_idx] == 0 ? moves : min(counter[jump_cell_idx], moves);
        counter[current_cell_idx + 1] = counter[current_cell_idx + 1] == 0 ? moves : min(counter[current_cell_idx + 1], moves);

        current_cell_idx = next_cell_idx;
    }
};
