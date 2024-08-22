// 476. Number Complement
// https://leetcode.com/problems/number-complement/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: highestOneBit OpenJDK algorithm from Hacker's Delight
class Solution {
public:
    int findComplement(int num) {
        // bitmask has the same length as num and contains only ones 1...1
        int bitmask = num;
        bitmask |= (bitmask >> 1);
        bitmask |= (bitmask >> 2);
        bitmask |= (bitmask >> 4);
        bitmask |= (bitmask >> 8);
        bitmask |= (bitmask >> 16);
        // flip all bits 
        return bitmask ^ num;
    }
};
