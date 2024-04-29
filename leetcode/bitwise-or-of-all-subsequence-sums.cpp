// 2505. Bitwise OR of All Subsequence Sums
// https://leetcode.com/problems/bitwise-or-of-all-subsequence-sums/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Prefix Sum
class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long long ans = 0, prefix_sum = 0;
        for (const int& num: nums) {
            prefix_sum += num;
            ans |= num | prefix_sum;
        }
        return ans;
    }
};
