// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Bit Manipulation
// Optimized with one best-performing solution
class Solution {
public:
    bool isPowerOfFour(int n) {
        // The number is power of two: n & (n - 1)) == 0
        // The number is even power of two: (n & 0xaaaaaaaa) == 0
        return n > 0 && (n & (n - 1)) == 0 && ((n & 0x55555555) != 0);
    }
};
