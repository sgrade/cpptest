// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Bit Manipulation : Constant-time Slice Using Bitmask
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if (n < 10) {
            return ans;
        }
        unordered_map<char, int> to_int = {
            {'A', 0}, 
            {'C', 1},
            {'G', 2},
            {'T', 3}
        };
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = to_int[s[i]];
        }
        int bitmask = 0;
        for (int i = 0; i < 10; ++i) {
            bitmask <<= 2;
            bitmask |= nums[i];
        }
        unordered_map<int, int> seen;
        ++seen[bitmask];
        for (int i = 10; i < n; ++i) {
            bitmask <<= 2;
            bitmask |= nums[i];
            bitmask &= ~(3 << 2 * 10);
            if (seen[bitmask] == 1) {
                ans.emplace_back(s.substr(i - 10 + 1, 10));
            }
            ++seen[bitmask];
        }
        return ans;
    }
};
