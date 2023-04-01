// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Dynamic Programming
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        int prev_prev = 1, prev = 2;
        n -= 2;
        int ans = 0;
        while (n--) {
            ans = prev_prev + prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
};
