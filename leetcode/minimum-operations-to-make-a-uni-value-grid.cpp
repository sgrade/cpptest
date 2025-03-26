// 2033. Minimum Operations to Make a Uni-Value Grid
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Two Pointers
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ans = 0;
            vector<int> nums(grid.size() * grid[0].size());
            int i = 0, rem = grid[0][0] % x;
            for (const vector<int>& row: grid) {
                for (const int& num: row) {
                    if (num % x != rem)
                        return -1;
                    nums[i++] = num;
                }
            }
            sort(nums.begin(), nums.end());

            int n = nums.size(), left = 0, right = n - 1;
            while (left < right) {
                int ops;
                if (left < n - right - 1) {
                    ops = (left + 1) * (nums[left + 1] - nums[left]) / x;
                    ans += ops;
                    ++left;
                }
                else {
                    ops = (n - right) * (nums[right] - nums[right - 1]) / x;
                    ans += ops;
                    --right;
                }
            }

            return ans;
        }
    };
