// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursion
// TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (p.size() == 0)
            return s.size() == 0;
        bool first_match = (
            s.size() > 0 &&
            (p[0] == s[0] || p[0] == '.')
        );

        if (p.size() >= 2 && p[1] == '*') {
            return (
                isMatch(s, p.substr(2)) ||
                (first_match && isMatch(s.substr(1), p))
            );
        }
        else {
            return (
                first_match &&
                isMatch(s.substr(1), p.substr(1))
            );
        }
    }
};
