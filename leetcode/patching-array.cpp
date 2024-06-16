// 330. Patching Array
// https://leetcode.com/problems/patching-array/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Solution
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0, i = 0, sz = nums.size();
        long first_missing = 1;
        while (first_missing <= n) {
            if (i <  sz && nums[i] <= first_missing)
                first_missing += nums[i++];
            else {
                first_missing += first_missing;
                ++ans;
            }
        }
        return ans;
    }
};
