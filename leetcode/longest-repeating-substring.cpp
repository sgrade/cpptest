// 1062. Longest Repeating Substring
// https://leetcode.com/problems/longest-repeating-substring/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        for (int len = n - 1; len > 0; --len) {
            for (int i = 0; i < n - len; ++i) {
                string candidate = s.substr(i, len);
                if (s.find(candidate, i + 1) != string::npos) {
                    return len;
                }
            }
        }
        return 0;
    }
};
