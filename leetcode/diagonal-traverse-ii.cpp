// 1424. Diagonal Traverse II
// https://leetcode.com/problems/diagonal-traverse-ii/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size(), cols = nums[0].size();
        vector<int> ans;
        for (int row = 0; row < rows; ++row) {
            cols = max(cols, (int)nums[row].size());
            int c = 0, r = row;
            while (r >= 0) {
                if (nums[r].size() > c)
                    ans.emplace_back(nums[r][c]);
                --r;
                ++c;
            }
        }
        for (int col = 1; col < cols; ++col) {
            int c = col, r = rows - 1;
            while (r >= 0 && c < cols) {
                if (nums[r].size() > c)
                    ans.emplace_back(nums[r][c]);
                    --r;
                    ++c;
            }
        }
        return ans;
    }
};
