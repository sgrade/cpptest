// 3560. Find Minimum Log Transportation Cost
// https://leetcode.com/problems/find-minimum-log-transportation-cost/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;
        if (n > k)
            ans += 1LL * (n - k) * k;
        if (m > k)
            ans += 1LL * (m - k) * k;
        return ans;
    }
};
