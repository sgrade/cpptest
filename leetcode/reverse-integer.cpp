// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int ans = 0, rem;
        int lim_pos = INT_MAX / 10;
        int lim_neg = INT_MIN / 10;
        while (x != 0) {
            rem = x % 10;
            x /= 10;
            if (ans > lim_pos || (ans == lim_pos && rem > 7)) return 0;
            if (ans < lim_neg || (ans == lim_neg && rem < -8)) return 0;
            ans = ans * 10 + rem;
        }
        return ans;
    }
};
