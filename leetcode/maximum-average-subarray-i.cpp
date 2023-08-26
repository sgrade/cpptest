// 643. Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = k;
        double sm = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double ans = sm / k;
        double current_ans;
        while (right < nums.size()) {
            sm -= nums[left];
            sm += nums[right];
            current_ans = sm / k;
            ans = max(ans, current_ans);
            ++left;
            ++right;
        }
        return ans;
    }
};
