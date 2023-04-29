// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <bits/stdc++.h>

using namespace std;


// Key idea is based on a Leetcode's Sample 87 ms submission
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!minq.empty() && minq.back() > nums[right])
                minq.pop_back();
            minq.emplace_back(nums[right]);
            while (!maxq.empty() && maxq.back() < nums[right])
                maxq.pop_back();
            maxq.emplace_back(nums[right]);
            if (maxq.front() - minq.front() <= limit) {
                ans = max(ans, right - left + 1);
            }
            else {
                if (minq.front() == nums[left])
                    minq.pop_front();
                if (maxq.front() == nums[left])
                    maxq.pop_front();
                ++left;
            }
        }
        return ans;
    }

private:
    deque<int> minq, maxq;
};
