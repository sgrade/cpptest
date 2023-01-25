// 909. Snakes and Ladders
// https://leetcode.com/problems/snakes-and-ladders/

#include <bits/stdc++.h>

using namespace std;


// The original solution from commit #c1ce5ed was corrected with 
// the ideas from Leetcode's Approach 1: Breadth-first search
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        rows = board.size();
        cols = board[0].size();
        max_idx = rows * rows;

        vector<int> dist(max_idx + 1, -1);  // distance from cell 1 to a cell with index i
        dist[1] = 0;
        vector<bool> dont_come_back(max_idx + 1);

        int current_cell_idx = 1;
        q.emplace(current_cell_idx);
        while (!q.empty()) {
            current_cell_idx = q.front();
            q.pop();
            move (board, dist, dont_come_back, current_cell_idx);
        }

        return dist[rows * rows];
    }

private:
    int rows, cols, max_idx;
    queue<int> q;
    void move (const vector<vector<int>>& board, vector<int>& dist, vector<bool>& dont_come_back, int& current_cell_idx) {
        for (int i = current_cell_idx + 1; i < min(current_cell_idx + 7, max_idx + 1); ++i) {
            auto [row, col] = getRowCol(i);
            int next_cell_idx = board[row][col] != -1 ? board[row][col] : i;
            if (dist[next_cell_idx] == -1) {
                dist[next_cell_idx] = dist[current_cell_idx] + 1;
                q.emplace(next_cell_idx);
            }
        }
    }

    pair<int, int> getRowCol (int& current_cell_idx) {
        int rem = current_cell_idx % rows;
        int row = rows - (current_cell_idx - 1) / rows - 1;
        int col;
        if (row % 2 != rows % 2) {  // left to right
            col = rem == 0 ? cols - 1 : rem - 1;
        }
        else {                      // right to left
            col = rem == 0 ? 0 : cols - rem;
        }
        return pair<int, int>(row, col);
    }
};
