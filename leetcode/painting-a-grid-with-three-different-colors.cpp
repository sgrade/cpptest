// 1931. Painting a Grid With Three Different Colors
// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial' Approach: State Compression Dynamic Programming
class Solution {
public:
    int colorTheGrid(int m, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, vector<int>> colors;
        int mask_end = pow(3, m);
        for (int mask = 0; mask < mask_end; ++mask) {
            vector<int> color;
            int cur = mask;
            for (int i = 0; i < m; ++i) {
                color.emplace_back(cur % 3);
                cur /= 3;
            }
            bool valid = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color[i] == color[i + 1]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                colors[mask] = color;
        }

        unordered_map<int, vector<int>> next_row;
        for (const auto& [mask1, color1]: colors) {
            for (const auto& [mask2, color2]: colors) {
                bool valid = true;
                for (int i = 0; i < m; ++i) {
                    if (color1[i] == color2[i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    next_row[mask1].emplace_back(mask2);
            }
        }

        vector<int> prev(mask_end);
        for (const auto& [mask, _]: colors)
            prev[mask] = 1;
        for (int i = 1; i < n; ++i) {
            vector<int> cur(mask_end);
            for (const auto& [mask2, _]: colors) {
                for (int mask1: next_row[mask2]) {
                    cur[mask2] += prev[mask1];
                    if (cur[mask2] >= MOD)
                        cur[mask2] -= MOD;
                }
            }
            prev = move(cur);
        }

        int ans = 0;
        for (const int& num: prev) {
            ans += num;
            if (ans >= MOD)
                ans -= MOD;
        }
        return ans;
    }

private:
    const int MOD = 1e9 + 7;

};
