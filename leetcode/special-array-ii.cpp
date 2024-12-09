// 3152. Special Array II
// https://leetcode.com/problems/special-array-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Sliding Window
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size(), right = 0;
        vector<int> max_reach(n);
        for (int left = 0; left < n; ++left) {
            right = max(left, right);
            while (right < n - 1 && nums[right] % 2 != nums[right + 1] % 2)
                ++right;
            max_reach[left] = right;
        }

        vector<bool> ans;
        for (const vector<int>& q: queries) {
            int left = q[0], right = q[1];
            ans.emplace_back(right <= max_reach[left]);
        }
        return ans;
    }
};
