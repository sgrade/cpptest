// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bit Manipulation: Short Language-Specific Solution
class Solution {
public:
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF;
        int ans, carry;
        while (b != 0) {
            ans = (a ^ b) & mask;
            carry = ((a & b) & mask) << 1;
            a = ans;
            b = carry;
        }
        return a;
    }
};
