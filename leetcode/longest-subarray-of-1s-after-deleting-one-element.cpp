// 1493. Longest Subarray of 1's After Deleting One Element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.emplace_back(0);
        int prev = 0, cur = 0, ans = 0, current_ans, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                ++cur;
                continue;
            }
            current_ans = prev + cur;
            ans = max(ans, current_ans);
            prev = cur;
            cur = 0;
        }
        if (ans == n - 1)
            --ans;
        return ans;
    }
};
