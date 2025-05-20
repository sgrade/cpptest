// 3355. Zero Array Transformation I
// https://leetcode.com/problems/zero-array-transformation-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Difference Array
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<int> diffs(n + 1);
        for (const vector<int>& q: queries) {
            int left = q[0], right = q[1];
            ++diffs[left];
            --diffs[right + 1];
        }

        vector<int> ops;
        int current = 0;
        for (const int& diff: diffs) {
            current += diff;
            ops.emplace_back(current);
        }
        for (int i = 0; i < n; ++i) {
            if (ops[i] < nums[i])
                return false;
        }
        return true;
    }
};
