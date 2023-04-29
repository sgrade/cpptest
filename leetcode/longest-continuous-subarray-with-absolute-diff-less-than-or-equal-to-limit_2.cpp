// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        ++cntr[nums[right]];
        while (right < nums.size()) {
            if (cntr.rbegin()->first - cntr.begin()->first <= limit) {
                ans = max(ans, right - left + 1);
                ++right;
                if (right == nums.size()) {
                    break;
                }
                ++cntr[nums[right]];
            }
            else {
                if (cntr[nums[left]] == 1)
                    cntr.erase(nums[left]);
                else
                    --cntr[nums[left]];
                ++left;
            }
        }
        return ans;
    }
private:
    int left = 0, right = 0;
    map<int, int> cntr;
};
