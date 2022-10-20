// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Hashmap
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        map<int, int> counter;
        
        for (const int &a: nums1) {
            for (const int &b: nums2) {
                ++counter[a + b];
            }
        }
        
        for (const int &c: nums3) {
            for (const int &d: nums4) {
                map<int, int>::iterator it = counter.find(-(c + d));
                if (it != counter.end()) {
                    ans += it->second;
                }
            }
        }
        
        return ans;
    }
};
