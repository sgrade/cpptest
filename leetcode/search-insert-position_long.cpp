// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, n = nums.size(), right = n - 1, mid, current;
        int mn = -10e4 - 1, mn_idx = 0, mx = 10e4 + 1, mx_idx = n;
        while (left <= right) {
            mid = left + (right - left) / 2;
            current = nums[mid];
            if (current == target) return mid;
            else if (current < target) {
                if (current > mn) {
                    mn = current;
                    mn_idx = mid;
                }
                left = mid + 1;
            }
            else {
                if (current < mx) {
                    mx = nums[mid];
                    mx_idx = mid;
                }
                right = mid - 1;
            }
        }
        return min(mn_idx + 1, mx_idx);
    }
};
