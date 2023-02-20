// 266. Palindrome Permutation
// https://leetcode.com/problems/palindrome-permutation/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<char> counter(26);
        for (const char& ch: s) ++counter[ch - 'a'];
        int odd = 0;
        for (int i = 0; i < 26; ++i) {
            if (counter[i] % 2 != 0) {
                ++odd;
            }
        }
        return odd < 2;
    }
};
