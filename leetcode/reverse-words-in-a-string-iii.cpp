// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        size_t n = s.size(), left = 0, right = 0;
        while (left < s.size()) {
            while (right < n && !isspace(s[right]))
                ++right;
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            while (left < n && s[left] == ' ')
                ++left;
            right = left;
        }
        return s;
    }
};
