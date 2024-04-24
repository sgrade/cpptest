// 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            if (n == 0) return 0;
            if (n == 1 || n == 2) return 1;
        }
        vector<int> t(4);
        t[2] = 1;
        t[3] = 1;
        for (int i = 3; i <= n; ++i) {
            rotate(t.begin(), t.begin() + 1, t.end());
            t[3] = t[0] + t[1] + t[2];
        }
        return t.back();
    }
};
