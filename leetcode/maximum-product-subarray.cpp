// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], mn = nums[0], mx = nums[0], tmp_mn;
        for (int i = 1; i < nums.size(); ++i) {
            tmp_mn = min({nums[i], mn * nums[i], mx * nums[i]});
            mx = max({nums[i], mn * nums[i], mx * nums[i]});
            mn = tmp_mn;   // tmp_mn was calculated with the prev mx (not mx on this step)
            ans = max(ans, mx);
        }
        return ans;
    }
};
