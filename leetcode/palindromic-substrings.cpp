// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #3: Expand Around Possible Centers
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += countAroundCenter(s, i, i);
            ans += countAroundCenter(s, i, i + 1);
        }
        return ans;
    }

    int countAroundCenter(const string& s, int left, int right) {
        int current_n = s.size(), current_ans = 0;
        while (left >= 0 && right < current_n) {
            if (s[left] != s[right])
                break;
            --left;
            ++right;
            ++current_ans;
        }
        return current_ans;
    }
};
