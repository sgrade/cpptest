// 1062. Longest Repeating Substring
// https://leetcode.com/problems/longest-repeating-substring/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int len = 1; len < n; ++len) {
            for (int i = 0; i < n - len; ++i) {
                string candidate = s.substr(i, len);
                if (s.find(candidate, i + 1) != string::npos) {
                    ans = len;
                    break;
                }
            }
        }
        return ans;
    }
};
