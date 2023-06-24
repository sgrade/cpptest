// 521. Longest Uncommon Subsequence I
// https://leetcode.com/problems/longest-uncommon-subsequence-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2 Simple Solution
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a != b)
            return max(a.size(), b.size());
        return -1;
    }
};
