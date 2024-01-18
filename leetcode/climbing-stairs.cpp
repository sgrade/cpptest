// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        int prev_prev = 1, prev = 2, cur;
        for (int i = 2; i < n; ++i) {
            cur = prev_prev + prev;
            prev_prev = prev;
            prev = cur;
        }
        return cur;
    }
};
