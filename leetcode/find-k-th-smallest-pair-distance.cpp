// 719. Find K-th Smallest Pair Distance
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Bucket Sort
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> bucket(mx + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distance = abs(nums[i] - nums[j]);
                ++bucket[distance];
            }
        }
        for (int dist = 0; dist <= mx; ++dist) {
            k -= bucket[dist];
            if (k <= 0)
                return dist;
        }
        return -1;
    }
};
