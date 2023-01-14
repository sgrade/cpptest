// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i = 1; i * i <= num; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
};
