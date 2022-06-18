// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        
        const int HALF_INT_MIN = INT_MIN >> 1;
        
        // handling overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // handling signs
        int negatives = 2;
        if (dividend > 0) {
            --negatives;
            dividend = -dividend;
        }
        if (divisor > 0) {
            --negatives;
            divisor = -divisor;
        }
        
        int quotient = 0;
        // remember that we work with negatives, 
        // so >= shows smaller number (which is closer to zero)
        while(divisor >= dividend) {
            // -1 is to for case (INT_MIN, -1)
            int power_of_two = -1;
            int tmp = divisor;
            while (tmp >= HALF_INT_MIN && tmp + tmp >= dividend) {
                tmp += tmp;
                power_of_two += power_of_two;
            }
            quotient += power_of_two;
            dividend -= tmp;
        }
        
        if (negatives != 1) {
            quotient = -quotient;
        }
        
        return quotient;
    }
};
