// 2108. Find First Palindromic String in the Array
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& s: words)
            if (isPalindrome(s))
                return s;
        return "";
    }
private:
    int n;
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};
