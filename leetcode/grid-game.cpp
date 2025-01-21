// 2017. Grid Game
// https://leetcode.com/problems/grid-game/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Prefix and Suffix Sum
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int cols = grid[0].size();
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bot = 0, ans = numeric_limits<long long>::max();
        for (int col = 0; col < cols; ++col) {
            top -= grid[0][col];
            ans = min(ans, max(top, bot));
            bot += grid[1][col];
        }
        return ans;
    }
};
