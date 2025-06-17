// 3405. Count the Number of Arrays with K Matching Adjacent Elements
// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's pproach: Combinatorial Mathematics
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        fact.resize(1e5), inv_fact.resize(1e5);
        fact[0] = 1;
        for (int i = 1; i < 1e5; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        inv_fact[1e5 - 1] = qpow(fact[1e5 - 1], MOD - 2);
        for (int i = 1e5 - 1; i; --i)
            inv_fact[i - 1] = inv_fact[i] * i % MOD;

        return getComb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }

private:
    const int MOD = 1e9 + 7;
    vector<long long> fact, inv_fact;

    long long qpow(long long x, int n) {
        long long ans = 1;
        while (n) {
            if (n & 1)
                ans = ans * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
    }

    long long getComb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
};
