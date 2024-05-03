// 1885. Count Pairs in Two Arrays
// https://leetcode.com/problems/count-pairs-in-two-arrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sort and Two Pointer
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i)
            diff[i] = nums1[i] - nums2[i];
        sort(diff.begin(), diff.end());

        long long ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (diff[left] + diff[right] > 0) {
                ans += right - left;
                --right;
            }
            else
                ++left;
        }
        return ans;
    }
};
