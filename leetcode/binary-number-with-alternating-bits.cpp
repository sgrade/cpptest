// 693. Binary Number with Alternating Bits
// https://leetcode.com/problems/binary-number-with-alternating-bits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prev = n & 1, cur;
        long x = 2;
        while (x <= n) {
            cur = n & x;
            if (cur == prev)
                return false;
            prev = cur;
            x = x << 1;
        }
        return true;
    }
};
