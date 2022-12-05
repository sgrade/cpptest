// 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Brian Kernighan's Algorithm
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return left & right;
    }
};
