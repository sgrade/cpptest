// 440. K-th Smallest in Lexicographical Order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    int findKthNumber(int n, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long x = 1;
        for (int i = 0; i < n; ++i) {
            --k;
            if (k == 0)
                return (int)x;
            if (x * 10 <= n) {
                x *= 10;
                continue;
            }
            while (x % 10 == 9 || x >= n)
                x /= 10;
            x += 1;
        }
        return -1;
    }
};
