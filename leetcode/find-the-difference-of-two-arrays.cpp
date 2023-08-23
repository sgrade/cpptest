// 2215. Find the Difference of Two Arrays
// https://leetcode.com/problems/find-the-difference-of-two-arrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (const int& num: st1) {
            if (st2.find(num) == st2.end())
                ans[0].emplace_back(num);
        }
        for (const int& num: st2) {
            if (st1.find(num) == st1.end())
                ans[1].emplace_back(num);
        }
        return ans;
    }
};
