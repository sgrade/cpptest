// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: A Better Binary Search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        int left = 0, right = n1;
        while (left <= right) {
            int partition_a = (left + right) / 2;
            int partition_b = (n1 + n2 + 1) / 2 - partition_a;
            
            int max_left_a = (partition_a == 0) ? INT_MIN : nums1[partition_a - 1];
            int min_right_a = (partition_a == n1) ? INT_MAX : nums1[partition_a];
            int max_left_b = (partition_b == 0) ? INT_MIN : nums2[partition_b - 1];
            int min_right_b = (partition_b == n2) ? INT_MAX : nums2[partition_b];

            if (max_left_a <= min_right_b && max_left_b <= min_right_a) {
                if ((n1 + n2) % 2 == 0)
                    return (max(max_left_a, max_left_b) + min(min_right_a, min_right_b)) / 2.0;
                else
                    return max(max_left_a, max_left_b);
            }

            else if (max_left_a > min_right_b)
                right = partition_a - 1;
            else
                left = partition_a + 1;
        }

        return 0.0;
    }
};
