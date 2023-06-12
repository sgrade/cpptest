// 2439. Minimize Maximum of Array
// https://leetcode.com/problems/minimize-maximum-of-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Prefix Sum + Greedy.
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 0, prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            ans = max(ans, (prefix_sum + i) / (i + 1));
        }
        return ans;
    }
};
