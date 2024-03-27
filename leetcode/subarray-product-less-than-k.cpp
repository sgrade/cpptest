// 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Using Sliding Window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (k < 2)
            return 0;

        int ans = 0, product = 1;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            while (product >= k)
                product /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};
