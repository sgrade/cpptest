// 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int tribonacci(int n) {
        vector<int> t(max(3, n + 1));
        t[1] = 1;
        t[2] = 1;
        for (int i = 3; i <= n; ++i) 
            t[i] = t[i - 3] + t[i - 2] + t[i - 1];
        return t[n];
    }
};
