// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        int prev_prev = 0, prev = 1, ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = prev_prev + prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
};
