// 2061. Number of Spaces Cleaning Robot Cleaned
// https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int rows = room.size(), cols = room[0].size();

        // right, down, left, up : 0, 1, 2, 3
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        vector<vector<vector<bool>>> visited(
            rows, vector<vector<bool>>(cols, vector<bool>(4)));

        int ans = 0;
        int dir = 0, r = 0, c = 0, next_r, next_c;
        while (true) {
            // Not cleaned yet
            if (room[r][c] == 0) {
                ++ans;
                // Mark cleaned
                room[r][c] = 2;
            }

            // We already tried that direction from current cell
            if (visited[r][c][dir])
                return ans;

            const auto& [r_diff, c_diff] = directions[dir];
            next_r = r + r_diff;
            next_c = c + c_diff;
            visited[r][c][dir] = true;

            // Turn
            if (next_r < 0 || next_r == rows ||
                next_c < 0 || next_c == cols ||
                room[next_r][next_c] == 1)
                dir = (dir + 1) % 4;
            // Move to the next cell
            else {
                r = next_r;
                c = next_c;
            }

        }
    }
};
