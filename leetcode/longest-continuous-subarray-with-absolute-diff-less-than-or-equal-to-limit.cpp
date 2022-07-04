// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // Some ideas are from https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609969/C%2B%2B-solution-with-detailed-explanation
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        int ans = 1;
        int left = 0, right = 0;
        multiset<int> sorted;
        for (; right < n; ++right) {
            sorted.emplace(nums[right]);
            while (!sorted.empty() && *sorted.rbegin() - *sorted.begin() > limit) {
                multiset<int>::iterator nxt = sorted.find(nums[left]);
                sorted.erase(nxt);
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
