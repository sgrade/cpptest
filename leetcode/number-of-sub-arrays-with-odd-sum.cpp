// 1524. Number of Sub-arrays With Odd Sum
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Prefix Sum with Odd-Even Counting
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for (const int& num: arr) {
            prefix_sum += num;
            if (prefix_sum % 2 == 0) {
                ans += odd;
                ++even;
            }
            else {
                ans += even;
                ++odd;
            }
            ans %= MOD;
        }
        return ans;
    }

private:
    const int MOD = 1e9 + 7;
    int odd = 0, even = 1, ans = 0, prefix_sum = 0;
};
