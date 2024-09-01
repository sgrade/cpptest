// 2022. Convert 1D Array Into 2D Array
// https://leetcode.com/problems/convert-1d-array-into-2d-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        if (m * n != original.size())
            return {};
        vector<vector<int>> ans(m, vector<int>(n));
        int i = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                ans[row][col] = original[i++];
            }
        }
        return ans;
    }
};
