// 1424. Diagonal Traverse II
// https://leetcode.com/problems/diagonal-traverse-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Breadth First Search
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();
        vector<int> ans;

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            ans.emplace_back(nums[row][col]);
            if (col == 0 && row + 1 < rows)
                q.emplace(row + 1, col);
            if (col + 1 < nums[row].size())
                q.emplace(row, col + 1);
        }

        return ans;
    }
};
