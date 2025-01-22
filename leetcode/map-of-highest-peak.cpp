// 1765. Map of Highest Peak
// https://leetcode.com/problems/map-of-highest-peak/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = isWater.size(), cols = isWater[0].size();
        ans.resize(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (isWater[r][c] == 1) {
                    q.emplace(r, c);
                    ans[r][c] = 0;
                }
            }
        }

        int height = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& [r_diff, c_diff]: directions) {
                    int new_r = r + r_diff, new_c = c + c_diff;
                    if (isValid(new_r, new_c)) {
                        q.emplace(new_r, new_c);
                        ans[new_r][new_c] = height;
                    }
                }
            }
            ++height;
        }

        return ans;
    }

private:
    int rows, cols;
    vector<vector<int>> ans;
    vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    bool isValid(int& r, int& c) {
        return r >= 0 && r < rows && c >= 0 && c < cols && ans[r][c] == -1;
    }
};
