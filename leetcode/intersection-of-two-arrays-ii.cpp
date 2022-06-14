// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(set_intersection(nums1.begin(), nums1.end(), 
            nums2.begin(), nums2.end(), nums1.begin()), 
            nums1.end());
        return nums1;
    }
};
