// 2040. Kth Smallest Product of Two Sorted Arrays
// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


// Based on Editorial's Approach 1: Binary Search + Binary Search
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n1 = nums1.size(), n2 = nums2.size();
        ll left = -1e10, right = 1e10;
        while (left <= right) {
            ll product_mid = (left + right) / 2;
            // number of products less than mid
            ll products = 0;
            for (int i = 0; i < n1; ++i)
                products += countProducts(nums2, nums1[i], product_mid);
            if (products < k)
                left = product_mid + 1;
            else
                right = product_mid - 1;
        }
        return left;
    }

private:
    int n1, n2;
    int countProducts(vector<int>& nums2, ll num1, ll product_mid) {
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            ll cur_product = nums2[mid2] * num1;
            if (num1 >= 0 && cur_product <= product_mid ||
                num1 < 0 && cur_product > product_mid)
                    left = mid2+ 1;
            else
                right = mid2 - 1;
        }
        if (num1 >= 0)
            return left;
        else
            return n2 - left;
    }
};
