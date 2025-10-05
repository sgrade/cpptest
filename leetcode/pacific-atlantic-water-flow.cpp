// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;


// TLE
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(), cols = heights[0].size();
        can_flow.resize(rows, vector<vector<bool>>(cols, vector<bool>(2)));
               
        int row, col, ocean;
        
        // Can flow to Pacific
        ocean = 0;
        row = 0;
        for (col = 0; col < cols; ++col) {
            can_flow[row][col][ocean] = true;
            bfs(row, col, ocean, heights);
        }
        col = 0;
        for (row = 0; row < rows; ++row) {
            can_flow[row][col][ocean] = true;
            bfs(row, col, ocean, heights);
        }

        // Can flow to Atlantic
        ocean = 1;
        row = rows - 1;
        for (col = 0; col < cols; ++col) {
            can_flow[row][col][ocean] = true;
            bfs(row, col, ocean, heights);
        }
        col = cols - 1;
        for (int row = 0; row < rows; ++row) {
            can_flow[row][col][ocean] = true;
            bfs(row, col, ocean, heights);
        }

        vector<vector<int>> ans;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (can_flow[r][c][1] && can_flow[r][c][2]) {
                    ans.emplace_back(vector<int>{r, c});
                }
            }
        }
        return ans;
    }
private:
    int rows, cols;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // keys: 0 - Pacific, 2 Atlantic; 
    // values: false - not visited or cannot flow, true - can flow
    vector<vector<vector<bool>>> can_flow;
    void bfs(const int row, const int col, const int ocean, const vector<vector<int>>& heights) {
        queue<pair<int, int>> q;
        q.emplace(row, col);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto [cur_r, cur_c] = q.front();
                q.pop();
                int cur_h = heights[cur_r][cur_c];
                for (const auto& [r_diff, c_diff]: directions) {
                    int r = cur_r + r_diff, c = cur_c + c_diff;
                    if (r < 0 || c < 0 || r == rows || r == cols) {
                        continue;
                    }
                    int h = heights[r][c];
                    if (h >= cur_h) {
                        can_flow[r][c][ocean] = true;
                        q.emplace(r, c);
                    }
                }
            }
        }
    }
};
