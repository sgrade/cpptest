// 1074. Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Number of Subarrays that Sum to Target: Horizontal 1D Prefix Sum
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        // prefix sum
        vector<vector<int>> ps(rows + 1, vector<int>(cols + 1));
        for (int row = 1; row < rows + 1; ++row) {
            for (int col = 1; col < cols + 1; ++col) {
                ps[row][col] = ps[row - 1][col] + ps[row][col - 1] - ps[row - 1][col - 1] + matrix[row - 1][col - 1];
            }
        }

        int ans = 0, cur_sum;
        map<int, int> mp;
        for (int r1 = 1; r1 < rows + 1; ++r1) {
            for (int r2 = r1; r2 < rows + 1; ++r2) {
                mp.clear();
                mp[0] = 1;
                for (int col = 1; col < cols + 1; ++col) {
                    cur_sum = ps[r2][col] - ps[r1 - 1][col];
                    if (mp.find(cur_sum - target) != mp.end())
                        ans += mp[cur_sum - target];
                    ++mp[cur_sum];
                }
            }
        }
        return ans;
    }
};
