// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long z1, z2;
        z1 = count(nums1.begin(), nums1.end(), 0LL);
        z2 = count(nums2.begin(), nums2.end(), 0LL);

        long long s1, s2;
        s1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        s2 = accumulate(nums2.begin(), nums2.end(), 0LL);

        if (s1 > s2) {
            swap(s1, s2);
            swap(z1, z2);
        }

        long long d = s2 - s1;
        if (d == 0 && z1 == 0 && z2 == 0)
            return s1;
        if (z1 == 0 || (z2 == 0 && z1 > d))
            return -1;

        long long ans = max(s1 + z1, s2 + z2);
        return ans;
    }
};
