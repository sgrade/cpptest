// 1220. Count Vowels Permutation
// https://leetcode.com/problems/count-vowels-permutation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming (Bottom-up)
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> a_permutation_cnt(n);
        vector<long> e_permutation_cnt(n);
        vector<long> i_permutation_cnt(n);
        vector<long> o_permutation_cnt(n);
        vector<long> u_permutation_cnt(n);
        a_permutation_cnt[0] = 1;
        e_permutation_cnt[0] = 1;
        i_permutation_cnt[0] = 1;
        o_permutation_cnt[0] = 1;
        u_permutation_cnt[0] = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i < n; ++i) {
            a_permutation_cnt[i] = (e_permutation_cnt[i - 1] + i_permutation_cnt[i - 1] + u_permutation_cnt[i - 1]) % MOD;
            e_permutation_cnt[i] = (a_permutation_cnt[i - 1] + i_permutation_cnt[i - 1]) % MOD;
            i_permutation_cnt[i] = (e_permutation_cnt[i - 1] + o_permutation_cnt[i - 1]) % MOD;
            o_permutation_cnt[i] = i_permutation_cnt[i - 1] % MOD;
            u_permutation_cnt[i] = (i_permutation_cnt[ i - 1] + o_permutation_cnt[i - 1]) % MOD;
        }

        long ans = 0;
        ans = (a_permutation_cnt[n - 1] + e_permutation_cnt[n - 1] + i_permutation_cnt[n - 1] + o_permutation_cnt[n - 1] + u_permutation_cnt[n - 1]) % MOD;
        return (int)ans;
    }
};
