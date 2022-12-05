// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>

using namespace std;


// Optimization of the solution is based on Leetcode's Approach #4 Using 2 pointers
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = numeric_limits<int>::max();
        int sm = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sm += nums[right];
            while (sm >= target) {
                ans = min(ans, right - left + 1);
                sm -= nums[left++];
            }
        }
        return ans == numeric_limits<int>::max() ? 0 : ans;
    }
};
