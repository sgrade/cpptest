// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <bits/stdc++.h>

using namespace std;


// Key idea is based on a Leetcode's Sample 87 ms submission
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        for (; right < nums.size(); ++right) {
            while (!minq.empty() && minq.back() > nums[right])
                minq.pop_back();
            minq.emplace_back(nums[right]);
            while (!maxq.empty() && maxq.back() < nums[right])
                maxq.pop_back();
            maxq.emplace_back(nums[right]);
            if (maxq.front() - minq.front() > limit) {
                if (minq.front() == nums[left])
                    minq.pop_front();
                if (maxq.front() == nums[left])
                    maxq.pop_front();
                ++left;
            }
        }
        return right - left;
    }

private:
    int left = 0, right = 0;
    deque<int> minq, maxq;
};
