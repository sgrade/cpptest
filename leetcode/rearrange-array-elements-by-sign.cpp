// 2149. Rearrange Array Elements by Sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Two Pointers
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};
