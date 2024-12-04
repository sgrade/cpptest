// 2825. Make String a Subsequence Using Cyclic Increments
// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Optimized Single Pass (Two Pointer)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n1 = str1.size(), n2 = str2.size();
        int idx2 = 0;
        for (int idx1 = 0; idx1 < n1 && idx2 < n2; ++idx1) {
            if (str1[idx1] == str2[idx2] || str1[idx1] + 1 == str2[idx2] || str1[idx1] - 25 == str2[idx2])
            ++idx2;
        }
        return idx2 == n2;
    }
};
