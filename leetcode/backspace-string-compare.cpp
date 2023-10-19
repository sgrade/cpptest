// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return FirstPass(s) == FirstPass(t);
    }
private:
    string FirstPass (string& s) {
        string ans;
        for (const char& ch: s) {
            if (ch != '#')
                ans += ch;
            else {
                if (!ans.empty())
                    ans.pop_back();
            }
        }
        return ans;
    }
};
