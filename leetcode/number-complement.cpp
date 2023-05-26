// 476. Number Complement
// https://leetcode.com/problems/number-complement/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Flip Bit by Bit
class Solution {
public:
    int findComplement(int num) {
        int temp = num, bit = 1;
        while (temp) {
            num = num ^ bit;
            bit <<= 1;
            temp >>= 1;
        }
        return num;
    }
};
