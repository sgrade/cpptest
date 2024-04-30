// 1915. Number of Wonderful Substrings
// https://leetcode.com/problems/number-of-wonderful-substrings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Count Parity Prefixes
// Optimized with ideas from the fastest solutions
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        long long ans = 0LL;

        vector<int> freq(1024);
        // Empty prefix
        freq[0] = 1;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            int bit_idx = word[i] - 'a';
            // Flip the bit in the prefix mask
            mask ^= (1 << bit_idx);
            ans += freq[mask];
            ++freq[mask];
            for (char ch = 'a'; ch <= 'j'; ++ch)
                ans += freq[mask ^ (1 << (ch - 'a'))];
        }
        return ans;
    }
};
