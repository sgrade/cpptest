// 2338. Count the Number of Ideal Arrays
// https://leetcode.com/problems/count-the-number-of-ideal-arrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Combinatorial Mathematics
const int MOD = 1e9 + 7, MAX_N = 1e4 + 10;
const int MAX_P = 15;   // prime factors
vector<vector<int>> c(MAX_N + MAX_P, vector<int>(MAX_P + 1));
vector<int> prime_factor_counter[MAX_N], sieve(MAX_N);   // min prime factor

class Solution {
public:
    Solution() {
        if (c[0][0])
            return;
        for (int i = 2; i < MAX_N; ++i) {
            if (sieve[i] != 0)
                continue;
            for (int j = i; j < MAX_N; j += i)
                sieve[j] = i;
        }
        for (int i = 2; i < MAX_N; ++i) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    ++cnt;
                }
                prime_factor_counter[i].emplace_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); ++j)
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }

    int idealArrays(int n, int maxValue) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans = 0;
        for (int x = 1; x <= maxValue; ++x) {
            long long multiple = 1;
            for (int p: prime_factor_counter[x])
                multiple = multiple * c[n + p - 1][p] % MOD;
            ans = (ans + multiple) % MOD;
        }
        return ans;
    }
};
