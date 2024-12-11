// 2779. Maximum Beauty of an Array After Applying Operation
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sliding Window
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(nums.begin(), nums.end());
        int right = 0, ans = 0;
        for (int left = 0; left < nums.size(); ++left) {
            while (right < nums.size() && nums[right] - nums[left] <= k * 2)
                ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};
