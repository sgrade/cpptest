// 3011. Find if Array Can Be Sorted
// https://leetcode.com/problems/find-if-array-can-be-sorted/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Bubble Sort
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<int> values = nums;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (values[j] <= values[j + 1])
                    continue;
                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                    swap(values[j], values[j + 1]);
                else
                    return false;
            }
        }
        return true;
    }
};
