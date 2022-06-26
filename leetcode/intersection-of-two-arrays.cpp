// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }
        unordered_set<int> n1(nums1.begin(), nums1.end());
        vector<int> ans;
        for (const int &el: nums2) {
            if (n1.find(el) != n1.end()) {
                ans.emplace_back(el);
                n1.erase(el);
            }
        }
        return ans;
    }
};
