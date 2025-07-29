// 2411. Smallest Subarrays With Maximum Bitwise OR
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Enumeration
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        constexpr int BIT_COUNT = 31;
        int n = nums.size();
        vector<int> pos(BIT_COUNT, -1), ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < BIT_COUNT; ++bit) {
                if (!(nums[i] & (1 << bit))) {
                    if (pos[bit] != -1)
                        j = max(j, pos[bit]);
                }
                else
                    pos[bit] = i;
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
};
