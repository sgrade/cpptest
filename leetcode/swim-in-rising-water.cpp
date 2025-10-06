// 778. Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/

#include <vector>
#include <queue>
#include <set>

using std::vector;
using std::priority_queue;
using std::pair;
using std::set;
using std::max;
using std::greater;


// Based on Editorial's Approach #1: Heap
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<int> seen;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.emplace(grid[0][0], pair<int, int>(0, 0));

        int ans= 0;
        while (!pq.empty()) {
            auto [height, coordinates] = pq.top();
            pq.pop();
            int row = coordinates.first, col = coordinates.second;
            ans = max(ans, grid[row][col]);
            if (row == rows - 1 && col == cols - 1) {
                return ans;
            }
            for (const auto& [r_diff, c_diff]: directions) {
                int r = row + r_diff, c = col + c_diff;
                int next = r * rows + c;
                if (r < 0 || c < 0 || r == rows || c == cols || seen.count(next)) {
                    continue;
                }
                pq.emplace(grid[r][c], pair<int, int>(r, c));
                seen.emplace(next);
            }
        }

        return -1;
    }
private:
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
