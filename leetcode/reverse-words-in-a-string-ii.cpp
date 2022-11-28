// 186. Reverse Words in a String II
// https://leetcode.com/problems/reverse-words-in-a-string-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0, right = 1;
        while (right < n) {
            while (right < n && !isspace(s[right])) {
                ++right;
            }
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right = left + 1;
        }
    }
};
