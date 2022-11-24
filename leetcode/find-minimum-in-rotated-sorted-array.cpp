// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = min(nums[0], nums[n - 1]);
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            ans = min(ans, nums[mid]);
            if (mid == 0) {
                left = mid + 1;
                continue;
            }
            if (mid == n - 1) {
                right = mid - 1;
                continue;
            }
            if (nums[mid] > nums[0]) {
                left = mid + 1;
                continue;
            }
            if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) {
                return min(ans, nums[mid]);
            }
            right = mid - 1;
        }
        return ans;
    }
};
