// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t s_len = s.size(), t_len = t.size();
        size_t s_idx = 0, t_idx = 0;
        while (s_idx < s_len) {
            while (t_idx < t_len && t[t_idx] != s[s_idx]) ++t_idx;
            if (t_idx == t_len) return false;
            ++s_idx;
            ++t_idx;
        }
        return s_idx == s_len ? true : false;
    }
};
