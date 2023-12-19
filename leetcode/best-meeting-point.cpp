// 296. Best Meeting Point
// https://leetcode.com/problems/best-meeting-point/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #3 (Sorting)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> r, c;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    r.emplace_back(row);
                    c.emplace_back(col);
                }
            }
        }
        int row = r[r.size() / 2];
        sort(c.begin(), c.end());
        int col = c[c.size() / 2];
        return (MinDistance1D(r, row) + MinDistance1D(c, col));
    }
private:
    int MinDistance1D(vector<int>& points, int& origin) {
        int dist = 0;
        for (const int& point: points)
            dist += abs(point - origin);
        return dist;
    }
};
