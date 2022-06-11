// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        bool found = false;
        int ans = n;
        
        int left = 0, right = 0, sum = 0;
        
        while (right < n) {
            
            sum += nums[right];
            
            while (sum > (total - x) && left <= right) {
                sum -= nums[left];
                ++left;
            }
            
            if (sum == (total - x)) {
                found = true;
                ans = min(ans, n - (right - left + 1));
            }
            
            ++right;
        }
        
        if (!found)
            return -1;
        else 
            return ans;
    }
};
