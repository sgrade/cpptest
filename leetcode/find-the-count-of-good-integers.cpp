// 3272. Find the Count of Good Integers
// https://leetcode.com/problems/find-the-count-of-good-integers/

#include <bits/stdc++.h>

using nmespace std;


// Based on Editorial's Approach 1: Enumeration + Permutations and Combinations
class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_set<string> st;
            int base = pow(10, (n - 1) / 2);
            int skip = n & 1;
            for (int i = base; i < base * 10; ++i) {
                string s = to_string(i);
                s += string(s.rbegin() + skip, s.rend());
                long long pal = stol(s);
                if (pal % k == 0) {
                    sort(s.begin(), s.end());
                    st.emplace(s);
                }
            }

            vector<long long> factorial(n + 1, 1);
            long long ans = 0;
            for (int i = 1; i <= n; ++i)
                factorial[i] = factorial[i - 1] * i;
            for (const string &s: st) {
                vector<int> cnt(10);
                for (const char& c: s)
                    ++cnt[c - '0'];
                long long current = (n - cnt[0]) * factorial[n - 1];
                for (const int& x: cnt)
                    current /= factorial[x];
                ans += current;
            }

            return ans;
        }
    };
