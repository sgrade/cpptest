// 1608. Special Array With X Elements Greater Than or Equal X
// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int x = n - i;
            if (nums[i] >= x && (i == 0 || nums[i - 1] < x))
                return x;
        }
        return -1;
    }
};
