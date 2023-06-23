// 507. Perfect Number
// https://leetcode.com/problems/perfect-number/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach #3 Optimal Solution
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) return false;
        int sm = 0;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                sm += i;
                if (i * i != num)
                    sm += num / i;
            }
        }
        // 1 and num/1 are included in sm. 
        // Thus, we need to substract num/1 (which is num) from sm
        if (sm - num == num)
            return true;
        return false;
    }
};
