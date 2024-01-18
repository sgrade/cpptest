// 2320. Count Number of Ways to Place Houses
// https://leetcode.com/problems/count-number-of-ways-to-place-houses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countHousePlacements(int n) {
        long long prev_prev = 1LL, prev = 2LL, cur = 2LL;
        for (int i = 2; i <= n; ++i) {
            cur = (prev_prev + prev) % MOD;
            prev_prev = prev;
            prev = cur;
        }
        cur = 1LL * cur * cur % MOD;
        return cur;
    }
private:
    long long MOD = 1e9 + 7;
};
