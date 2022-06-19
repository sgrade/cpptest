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
        return recursivePow(x, N);
    }
    
    double recursivePow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = recursivePow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        }
        else {
            return half * half * x;
        }
    }
};
