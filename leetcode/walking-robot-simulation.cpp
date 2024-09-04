// 874. Walking Robot Simulation
// https://leetcode.com/problems/walking-robot-simulation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Simulation
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<int> st;
        for (const vector<int>& obstacle: obstacles)
            st.emplace(GetHash(obstacle[0], obstacle[1]));
        pair<int, int> pos = {0, 0};
        int dir = 0;
        for (const int& command: commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
                continue;
            }
            if (command == -2) {
                dir = (dir + 3) % 4;
                continue;
            }
            auto& [x_diff, y_diff] = directions[dir];
            for (int step = 0; step < command; ++step) {
                int x = pos.first + x_diff;
                int y = pos.second + y_diff;
                int coordinates = GetHash (x, y);
                if (st.find(coordinates) != st.end())
                    break;
                pos.first = x;
                pos.second = y;
            }
            ans = max(ans, pos.first * pos.first + pos.second * pos.second);
        }
        return ans;
    }
private:
    int ans = 0;
    const int HASH = 30001;
    int GetHash (int x, int y) {
        return x + HASH * y;
    }
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
};
