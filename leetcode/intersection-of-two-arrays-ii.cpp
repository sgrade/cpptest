// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size())
            return (intersect(nums2, nums1));
        unordered_map<int, int> counter;
        for (const int& num: nums2)
            ++counter[num];
        int i = 0;
        for (const int& num: nums1) {
            if (counter[num] > 0) {
                --counter[num];
                nums2[i++] = num;
            }
        }
        return vector<int> (nums2.begin(), nums2.begin() + i);
    }
};
