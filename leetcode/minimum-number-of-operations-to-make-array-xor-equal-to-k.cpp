// 2997. Minimum Number of Operations to Make Array XOR Equal to K
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = 0;
        for (const int& num: nums) {
            n ^= num;
        }
        n ^= k;
        int x = 1, ans = 0;
        for (int i = 0; i < 31; ++i) {
            if (x & n)
                ++ans;
            x <<= 1;
        }
        return ans;
    }
};
