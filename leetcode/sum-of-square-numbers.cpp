// 633. Sum of Square Numbers
// https://leetcode.com/problems/sum-of-square-numbers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Using Sqrt Function
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a_squared = 0;
        double b;
        for (long a = 0; a_squared <= c; ++a) {
            b = sqrt(c - a_squared);
            if (b == (int) b)
                return true;
            a_squared = a * a;
        }
        return false;
    }
};
