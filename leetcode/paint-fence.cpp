// 276. Paint Fence
// https://leetcode.com/problems/paint-fence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        int prev_prev = k, prev = k * k, cur;
        for (int i = 3; i <= n; ++i) {
            cur = (k - 1) * (prev_prev + prev);
            prev_prev = prev;
            prev = cur;
        }
        return cur;
    }
};
