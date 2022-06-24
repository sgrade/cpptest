// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                bool l = isPalindrome(s, left + 1, right);
                bool r = isPalindrome(s, left, right - 1);
                return l || r;
            }
            ++left;
            --right;
        }
        return true;
    }
    
    bool isPalindrome (const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
