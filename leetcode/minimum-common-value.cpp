// 2540. Minimum Common Value
// https://leetcode.com/problems/minimum-common-value/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 2: Two Pointers
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1] < nums2[i2])
                ++i1;
            else if (nums2[i2] < nums1[i1])
                ++i2;
            else
                return nums1[i1];
        }
        return -1;
    }
};
