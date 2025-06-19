// 2294. Partition Array Such That Maximum Difference Is K
// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(nums.begin(), nums.end());
        int ans = 1, mn_idx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[mn_idx] > k) {
                ++ans;
                mn_idx = i;
            }
        }
        return ans;
    }
};
