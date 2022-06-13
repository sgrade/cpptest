// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        backtrack(n, ans, s, 0, 0);
        return ans;
    }
    
    void backtrack(const int& n, vector<string>& ans, string s, int open, int close) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            s += '(';
            backtrack(n, ans, s, open + 1, close);
            s.pop_back();
        }
        if (close < open) {
            s += ')';
            backtrack(n, ans, s, open, close + 1);
            s.pop_back();
        }
    }
};
