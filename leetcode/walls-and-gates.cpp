// 286. Walls and Gates
// https://leetcode.com/problems/walls-and-gates/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach #2 (Breadth-first Search)
// SLOW
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        rows = rooms.size(), cols = rooms[0].size();
        queue<vector<int>> q;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (rooms[row][col] == 0) q.emplace(vector<int>{row, col});
            }
        }
        while (!q.empty()) {
            vector<int> gate = q.front();
            q.pop();
            int row = gate[0], col = gate[1];
            check(rooms, q, row + 1, col, rooms[row][col]);
            check(rooms, q, row, col + 1, rooms[row][col]);
            check(rooms, q, row - 1, col, rooms[row][col]);
            check(rooms, q, row, col - 1, rooms[row][col]);
        }
    }
private:
    const int EMPTY = 2147483647;
    int rows, cols;
    void check(vector<vector<int>>& rooms, queue<vector<int>>& q, int row, int col, int d) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || rooms[row][col] != EMPTY) return;
        rooms[row][col] = d + 1;
        q.emplace(vector<int>{row, col});
    }
};
