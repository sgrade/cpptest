// 440. K-th Smallest in Lexicographical Order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Prefix Tree
class Solution {
public:
    int findKthNumber(int n, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        this->k = k;
        int x = 1;
        --k;
        while (k > 0) {
            int steps = CountSteps(x, x + 1);
            if (steps <= k) {
                ++x;
                k -= steps;
            }
            else {
                x *= 10;
                --k;
            }
        }
        return x;
    }

private:
    long n, k;
    int CountSteps(long prefix1, long prefix2) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += min(n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};
