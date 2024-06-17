// 945. Minimum Increment to Make Array Unique
// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int level = nums[0], i = 1, ans = 0;
        while (i < n) {
            level = max(level + 1, nums[i]);
            if (nums[i] < level)
                ans += level - nums[i];
            ++i;
        }
        return ans;
    }
};
