// 2661. First Completely Painted Row or Column
// https://leetcode.com/problems/first-completely-painted-row-or-column/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Reverse Mapping
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int sz = arr.size();
        vector<int> num_to_idx(sz + 1);
        for (int i = 0; i < sz; ++i)
            num_to_idx[arr[i]] = i;

        int ans = INT_MAX, rows = mat.size(), cols = mat[0].size();

        for (int row = 0; row < rows; ++row) {
            int last_idx = INT_MIN;
            for (int col = 0; col < cols; ++col) {
                int idx = num_to_idx[mat[row][col]];
                last_idx = max(last_idx, idx);
            }
            ans = min(ans, last_idx);
        }

        for (int col = 0; col < cols; ++col) {
            int last_idx = INT_MIN;
            for (int row = 0; row < rows; ++row) {
                int idx = num_to_idx[mat[row][col]];
                last_idx = max(last_idx, idx);
            }
            ans = min(ans, last_idx);
        }

        return ans;
    }
};
