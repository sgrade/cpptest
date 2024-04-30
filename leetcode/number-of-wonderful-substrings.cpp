// 1915. Number of Wonderful Substrings
// https://leetcode.com/problems/number-of-wonderful-substrings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Count Parity Prefixes
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        long long ans = 0LL;

        unordered_map<int, int> freq;
        // Empty prefix
        freq.emplace(0, 1);
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            int bit_idx = word[i] - 'a';
            // Flip the bit in the prefix mask
            mask ^= (1 << bit_idx);
            ans += freq[mask];
            ++freq[mask];
            for (int char_idx = 0; char_idx < 10; ++char_idx) {
                int target = mask ^ (1 << char_idx);
                if (freq.find(target) != freq.end())
                    ans += freq[target];
            }
        }
        return ans;
    }
};
