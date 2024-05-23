// 2597. The Number of Beautiful Subsets
// https://leetcode.com/problems/the-number-of-beautiful-subsets/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Using Bitset
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        return Count(nums, 0, 0);
    }
private:
    int n, k;
    int ans = 0;
    int Count(const vector<int>& nums, int idx, int mask) {
        if (idx == n)
            return mask > 0 ? 1 : 0;
        bool is_beautiful = true;
        for (int i = 0; i < idx && is_beautiful; ++i) {
            is_beautiful = ((1 << i) & mask) == 0 || abs(nums[i] - nums[idx]) != k;
        }

        int skip = Count(nums, idx + 1, mask);
        int take = 0;
        if (is_beautiful)
            take = Count(nums, idx + 1, mask + (1 << idx));

        return skip + take;
    }
};
