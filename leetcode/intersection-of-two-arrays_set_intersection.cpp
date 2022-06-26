// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>

using namespace std;

// NOTE: this solution is useful, when the input arrays are sorted
// So we can avoid creating the sorted ranges (sets) and get linear time
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1(nums1.begin(), nums1.end());
        set<int> n2(nums2.begin(), nums2.end());
        vector<int> ans;
        set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), back_inserter(ans));
        return ans;
    }
};
