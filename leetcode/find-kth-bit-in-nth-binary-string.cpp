// 1545. Find Kth Bit in Nth Binary String
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Recursion
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';
        int len = 1 << n;
        if (k < len / 2) 
            return findKthBit(n - 1, k);
        else if (k == len / 2)
            return '1';
        else {
            char bit = findKthBit(n - 1, len - k);
            // in the first half the bit is inverted;
            return bit == '0' ? '1' : '0';
        }
    }
};
