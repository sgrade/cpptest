// 1913. Maximum Product Difference Between Two Pairs
// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // from smallest to largest
        int mn1 = 1e4, mn2 = 1e4, mx1 = 0, mx2 = 0;
        for (const int& num: nums) {
            if (num > mx2) {
                mx1 = mx2;
                mx2 = num;
            }
            else
                mx1 = max(mx1, num);
            if (num < mn1) {
                mn2 = mn1;
                mn1 = num;
            }
            else
                mn2 = min(mn2, num);
        }
        return mx2 * mx1 - mn1 * mn2;
    }
};
