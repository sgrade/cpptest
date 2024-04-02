// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> chars(128, 0);
        vector<bool> mapped(128);
        size_t idx_s, idx_t;
        for (int i = 0; i < s.size(); ++i) {
            idx_s = s[i] - 0;
            idx_t = t[i] - 0;
            if (chars[idx_s] == t[i])
                continue;
            else {
                if (chars[idx_s] != 0)
                    return false;
                if (mapped[idx_t])
                    return false;
                chars[idx_s] = t[i];
                mapped[idx_t] = true;
            }
        }
        return true;
    }
};
