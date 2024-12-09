// 1891. Cutting Ribbons
// https://leetcode.com/problems/cutting-ribbons/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Binary Search on The Answer
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->k = k;
        int left = 0, right = *max_element(ribbons.begin(), ribbons.end());
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (isPossible(mid, ribbons))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }

private:
    int k;
    bool isPossible(int x, vector<int>& ribbons) {
        int count = 0;
        for (const int& ribbon: ribbons) {
            int pieces = ribbon / x;
            count += pieces;
            if (count >= k)
                return true;
        }
        return false;
    }
};
