// 2486. Append Characters to String to Make Subsequence
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int appendCharacters(string s, string t) {
        int size_s = s.size(), size_t = t.size();
        int idx_s = 0, idx_t = 0;
        while (idx_s < size_s && idx_t < size_t) {
            if (s[idx_s++] == t[idx_t])
                ++idx_t;
        }
        return size_t - idx_t;
    }
};
