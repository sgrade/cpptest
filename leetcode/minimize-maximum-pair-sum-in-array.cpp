// 1877. Minimize Maximum Pair Sum in Array
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = 0;
        for (int i = 0; i < n/2; ++i)
            mx = max(mx, nums[i] + nums[n - 1 - i]);
        return mx;
    }
};
