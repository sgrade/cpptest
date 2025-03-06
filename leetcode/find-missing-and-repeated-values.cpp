// 2965. Find Missing and Repeated Values
// https://leetcode.com/problems/find-missing-and-repeated-values/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = grid.size();
            vector<int> ans(2);
            unordered_set<int> seen;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int num = grid[i][j];
                    if (seen.find(num) != seen.end())
                        ans[0] = num;
                    seen.emplace(num);
                }
            }
            int num = 1, ceil = n * n + 1;
            while (num < ceil) {
                if (seen.find(num) == seen.end()) {
                    ans[1] = num;
                    break;
                }
                ++num;
            }
            return ans;
        }
    };
