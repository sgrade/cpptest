// 2460. Apply Operations to an Array
// https://leetcode.com/problems/apply-operations-to-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == 0)
                continue;
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> ans(n);
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] != 0)
                ans[i++] = nums[j];
        }
        return ans;
    }
};
