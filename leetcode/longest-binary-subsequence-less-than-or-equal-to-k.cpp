// 2311. Longest Binary Subsequence Less Than or Equal to K
// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Greedy
class Solution {
public:
    int longestSubsequence(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int sum = 0, ans = 0, n = s.size();
        // Number of bits to represent k;
        int total_bits = 32 - __builtin_clz(k);
        for (int i = 0; i < n; ++i) {
            char ch = s[n - 1 - i];
            if (ch == '0')
                ++ans;
            else {
                if (i < total_bits && sum + (1 << i) <= k) {
                    sum += 1 << i;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
