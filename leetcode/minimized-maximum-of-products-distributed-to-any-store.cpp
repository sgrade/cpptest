// 2064. Minimized Maximum of Products Distributed to Any Store
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Binary Search on The Answer
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        int left = 0, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid, quantities))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

private:
    int n;
    bool canDistribute(int& x, vector<int>& quantities) {
        int first_not_distributed = 0;
        int remaining = quantities[first_not_distributed];
        for (int i = 0; i < n; ++i) {
            if (remaining <= x) {
                ++first_not_distributed;
                if (first_not_distributed == quantities.size())
                    return true;
                remaining = quantities[first_not_distributed];
            }
            else {
                remaining -= x;
            }
        }
        return false;
    }
};
