// 1922. Count Good Numbers
// https://leetcode.com/problems/count-good-numbers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Fast Exponentiation
class Solution {
    public:
        int countGoodNumbers(long long n) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            long long even = (long long) calculate (5, (n + 1) / 2);
            long long odd = (long long) calculate (4, n / 2);
            long long ans = (long long) even * odd % MOD;
            return ans;
        }

    private:
        const int MOD = 1e9 + 7;
        int calculate (int x, long long y) {
            int reminder = 1, multiple = x;
            while (y > 0) {
                if (y % 2 == 1)
                    reminder = (long long)reminder * multiple % MOD;
                multiple = (long long)multiple * multiple % MOD;
                y /= 2;
            }
            return reminder;
        }
    };
