// 2570. Merge Two 2D Arrays by Summing Values
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1][0] == nums2[i2][0]) {
                int id = nums1[i1][0], 
                sum = nums1[i1][1] + nums2[i2][1];
                ans.emplace_back(vector<int>{id, sum});
                ++i1, ++i2;
            }
            else if (nums1[i1][0] < nums2[i2][0])
                ans.emplace_back(nums1[i1++]);
            else
                ans.emplace_back(nums2[i2++]);
        }
        while (i1 < n1)
            ans.emplace_back(nums1[i1++]);
        while (i2 < n2)
            ans.emplace_back(nums2[i2++]);
        return ans;
    }
};
