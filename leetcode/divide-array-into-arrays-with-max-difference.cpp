// 2966. Divide Array Into Arrays With Max Difference
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort (nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans(n / 3, vector<int>(3));
        ans[0][0] = nums[0];
        for (int i = 1; i < n; ++i) {
            int idx1 = i / 3, idx2 = i % 3;
            ans[idx1][idx2] = nums[i];
            if (idx2 == 0)
                continue;
            if (ans[idx1][idx2] - ans[idx1][0] > k)
                return {};
        }
        return ans;
    }
};
