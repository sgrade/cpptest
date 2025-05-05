// 790. Domino and Tromino Tiling
// https://leetcode.com/problems/domino-and-tromino-tiling/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming (Top-down)
class Solution {
    public:
        int numTilings(int n) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ans = (int)f(n);
            return ans;
        }

    private:
        int MOD = 1e9 + 7;

        // f - fully cover board; p - partially
        unordered_map<int, long> f_cache, p_cache;

        long p(int n) {
            if (p_cache.find(n) != p_cache.end())
                return p_cache[n];
            long ans;
            if (n == 2)
                ans = 1L;
            else
                ans = (p(n - 1) + f(n - 2)) % MOD;
            p_cache[n] = ans;
            return ans;
        }

        long f(int n) {
            if (f_cache.find(n) != f_cache.end())
                return f_cache[n];
            long ans;
            if (n == 1)
                ans = 1L;
            else if (n == 2)
                ans = 2L;
            else
                ans = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD;
            f_cache[n] = ans;
            return ans;
        }
    };
