// 1685. Sum of Absolute Differences in a Sorted Array
// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for (int i = 1; i < n; ++i)
            ans[i] = ans[i - 1] + nums[i];

        int prev = ans[0], last = ans[n - 1];
        ans[n - 1] = nums[n - 1] * (n - 1) - ans[n - 2];
        ans[0] = last - nums[0] * n;

        for (int i = 1; i < n - 1; ++i) {
            int temp = ans[i];
            ans[i] = (nums[i] * i - prev) + (last - prev - nums[i] * (n - i));
            prev = temp;
        }

        return ans;
    }
};
