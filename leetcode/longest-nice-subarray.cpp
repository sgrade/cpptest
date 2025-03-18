// 2401. Longest Nice Subarray
// https://leetcode.com/problems/longest-nice-subarray/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sliding Window
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int used = 0, left = 0, ans = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while ((used & nums[right]) != 0)
                    used ^= nums[left++];
                used |= nums[right];
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };
