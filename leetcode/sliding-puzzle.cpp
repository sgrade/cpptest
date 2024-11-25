// 773. Sliding Puzzle
// https://leetcode.com/problems/sliding-puzzle/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Breadth-First Search (BFS)
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j)
                start += to_string(board[i][j]);
        }

        unordered_set<string> visited;
        queue<string> q;
        q.emplace(start);
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();
                if (current == target)
                    return moves;
                int zero_pos = current.find('0');
                for (const int& new_pos: directions[zero_pos]) {
                    string next = current;
                    swap(next[zero_pos], next[new_pos]);
                    if (visited.find(next) != visited.end())
                        continue;
                    visited.emplace(next);
                    q.emplace(next);
                }
            }
            ++moves;
        }
        return -1;
    }

private:
    vector<vector<int>> directions = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {1, 3, 5},
        {2, 4}
    };
    string target = "123450";
    string start;
};
