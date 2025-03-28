// 2503. Maximum Number of Points From Grid Queries
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sorting Queries + Min-Heap Expansion
class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            rows = grid.size(), cols = grid[0].size(), q = queries.size();

            vector<int> ans(q);
            vector<pair<int, int>> sorted(q);
            for (int i = 0; i < q; ++i)
                sorted[i] = {queries[i], i};
            sort(sorted.begin(), sorted.end());

            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            vector<vector<bool>> visited(rows, vector<bool>(cols));
            int points = 0;
            pq.emplace(grid[0][0], pair<int, int>(0, 0));
            visited[0][0] = true;

            for (const auto& [query, i]: sorted) {
                while (!pq.empty() && pq.top().first < query) {
                    auto [cell, coordinates] = pq.top();
                    pq.pop();
                    int row = coordinates.first, col = coordinates.second;
                    ++points;
                    for (const auto& [r_diff, c_diff]: directions) {
                        int r = row + r_diff, c = col + c_diff;
                        if (r >= 0 && c >= 0 && r < rows && c < cols && !visited[r][c]) {
                            pq.emplace(grid[r][c], pair<int, int>(r, c));
                            visited[r][c] = true;
                        }
                    }
                }
                ans[i] = points;
            }

            return ans;
        }

    private:
        int rows, cols, q;
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
    };
