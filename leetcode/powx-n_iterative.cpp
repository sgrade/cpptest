// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        
        // Int N won't work for the following input:
        // x = 1.00000
        // n = -2147483648
        long long N = n;
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1;
        double cur = x;
        
        for (long long i = N; i > 0; i /= 2) {
            if (i % 2 == 1) {
                ans = ans * cur;
            }
            cur = cur * cur;
        }
        
        return ans;
    }
};
