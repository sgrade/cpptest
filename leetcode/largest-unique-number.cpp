// Approach 1: Sorting
// https://leetcode.com/problems/largest-unique-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size(); ++i) {
            if (i == nums.size() - 1) {
                if (i == 0 || nums[i] != nums[i - 1])
                    return nums[i];
                else
                    continue;
            }
            if (nums[i] == nums[i + 1])
                continue;
            if (i == 0 || nums[i] != nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};
