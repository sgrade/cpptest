// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int left = 0, right = left;
        while (left < n) {
            while (left < n && isspace(s[left])) {
                s.erase(left, 1);
                --n;
            }
            right = left;
            while (right < n && !isspace(s[right])) {
                ++right;
            }
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
        }
        if (isspace(s.back())) {
            s.pop_back();
        }
        return s;        
    }
};
