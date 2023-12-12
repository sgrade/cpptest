// 1464. Maximum Product of Two Elements in an Array
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0, mx2 = 0;
        for (const int& num: nums) {
            if (num >= mx2) {
                mx2 = num;
                if (mx2 > mx1)
                    swap(mx1, mx2);
            }
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};
