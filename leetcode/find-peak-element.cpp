// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Iterative Binary Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
