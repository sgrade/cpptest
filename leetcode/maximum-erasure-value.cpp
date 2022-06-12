// 1695. Maximum Erasure Value
// https://leetcode.com/problems/maximum-erasure-value/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> uniq;
        int left = 0, right = 0, sum = 0, ans = nums[0];
        for (; right < nums.size(); ++right) {
            while(uniq.find(nums[right]) != uniq.end()) {
                uniq.erase(nums[left]);
                sum -= nums[left];
                ++left;
            }
            uniq.insert(nums[right]);
            sum += nums[right];
            ans = max(ans, sum);
        }
        return ans;
    }
};
