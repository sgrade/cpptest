// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
