// 2044. Count Number of Maximum Bitwise-OR Subsets
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Bit Manipulation
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int max_or = 0;
        for (const int& num: nums)
            max_or |= num;

        int subsets = 1 << nums.size();
        int ans = 0;

        for (int mask = 1; mask < subsets; ++mask) {
            int current_or = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int shifted_mask = mask >> i;
                if (shifted_mask & 1)
                    current_or |= nums[i];
            }
            if (current_or == max_or)
                ++ans;
        }

        return ans;
    }
};
