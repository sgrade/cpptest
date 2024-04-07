// 678. Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0, stars = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                ++stars;
                continue;
            }
            if (s[i] == '(')
                ++balance;
            else
                --balance;
            if (balance < 0) {
                if (stars <= 0)
                    return false;
                ++balance;
                --stars;
            }
        }

        balance = 0, stars = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '*') {
                ++stars;
                continue;
            }
            if (s[i] == ')')
                ++balance;
            else
                --balance;
            if (balance < 0) {
                if (stars <= 0)
                    return false;
                ++balance;
                --stars;
            }
        }

        return true;
    }
};
