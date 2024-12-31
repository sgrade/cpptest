// 1746. Maximum Subarray Sum After One Operation
// https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: MaxLeft and MaxRight
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = nums.size();
        max_left.resize(n), max_right.resize(n);
        for (int i = 1; i < n; ++i)
            max_left[i] = max(max_left[i - 1] + nums[i - 1], 0);
        for (int i = n - 2; i >= 0; --i)
            max_right[i] = max(max_right[i + 1] + nums[i + 1], 0);

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, max_left[i] + nums[i] * nums[i] + max_right[i]);

        return ans;
    }
private:
    int n;
    vector<int> max_left, max_right;
};
