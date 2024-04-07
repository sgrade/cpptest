// 678. Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from Editorial's Approach 4: Two Pointer
class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0, stars = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '*')
                ++balance;
            else
                --balance;
            if (balance < 0)
                return false;
        }

        balance = 0, stars = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*')
                ++balance;
            else
                --balance;
            if (balance < 0)
                return false;
        }

        return true;
    }
};
