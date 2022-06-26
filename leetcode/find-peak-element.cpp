// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = -1;
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
