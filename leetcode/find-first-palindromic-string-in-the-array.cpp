// 2108. Find First Palindromic String in the Array
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& s: words) {
            // From https://en.cppreference.com/w/cpp/algorithm/equal
            if (std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin()))
                return s;
        }
        return "";
    }
};
