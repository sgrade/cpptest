// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        can_flow.assign(rows, vector<vector<bool>>(cols, vector<bool>(2, false)));

        // multi-source BFS for Pacific (ocean = 0)
        {
            int ocean = 0;
            queue<pair<int, int>> q;
            for (int c = 0; c < cols; ++c) {
                if (!can_flow[0][c][ocean]) {
                    can_flow[0][c][ocean] = true;
                    q.emplace(0, c);
                }
            }
            for (int r = 0; r < rows; ++r) {
                if (!can_flow[r][0][ocean]) {
                    can_flow[r][0][ocean] = true;
                    q.emplace(r, 0);
                }
            }
            bfs(q, ocean, heights);
        }

        // multi-source BFS for Atlantic (ocean = 1)
        {
            int ocean = 1;
            queue<pair<int, int>> q;
            for (int c = 0; c < cols; ++c) {
                if (!can_flow[rows - 1][c][ocean]) {
                    can_flow[rows - 1][c][ocean] = true;
                    q.emplace(rows - 1, c);
                }
            }
            for (int r = 0; r < rows; ++r) {
                if (!can_flow[r][cols - 1][ocean]) {
                    can_flow[r][cols - 1][ocean] = true;
                    q.emplace(r, cols - 1);
                }
            }
            bfs(q, ocean, heights);
        }

        vector<vector<int>> ans;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (can_flow[r][c][0] && can_flow[r][c][1]) {
                    ans.emplace_back(vector<int>{r, c});
                }
            }
        }
        return ans;
    }

private:
    int rows;
    int cols;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // can_flow[r][c][0] -> Pacific, can_flow[r][c][1] -> Atlantic
    vector<vector<vector<bool>>> can_flow;

    void bfs(queue<pair<int, int>>& q, const int ocean, const vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto [cur_r, cur_c] = cur;
            int cur_h = heights[cur_r][cur_c];
            for (const auto& [r_diff, c_diff] : directions) {
                int r = cur_r + r_diff;
                int c = cur_c + c_diff;
                if (r < 0 || c < 0 || r >= rows || c >= cols) {
                    continue;
                }
                if (can_flow[r][c][ocean]) {
                    continue;
                }
                if (heights[r][c] < cur_h) {
                    continue;
                }
                can_flow[r][c][ocean] = true;
                q.emplace(r, c);
            }
        }
    }
};
