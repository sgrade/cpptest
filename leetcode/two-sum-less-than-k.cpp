// 1099. Two Sum Less Than K
// https://leetcode.com/problems/two-sum-less-than-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int ans = -1;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int sum;
        while (i < j) {
            sum = nums[i] + nums[j];
            if (sum < k) {
                ans = max(ans, sum);
                ++i;
            }
            else {
                --j;
            }
        }
        return ans;
    }
};
