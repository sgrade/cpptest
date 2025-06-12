// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i)
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        ans = max(ans, abs(nums[0] - nums[nums.size() - 1]));
        return ans;
    }
};
