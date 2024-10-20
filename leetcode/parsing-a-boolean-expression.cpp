// 1106. Parsing A Boolean Expression
// https://leetcode.com/problems/parsing-a-boolean-expression/


#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: String Manipulation
class Solution {
public:
    bool parseBoolExpr(string expression) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        while (expression.size() > 1) {
            int left = expression.find_last_of("!|&");
            int right = expression.find(')', left);
            int len = right - left + 1;
            string subexpr = expression.substr(left, len);
            char ans = Evaluate (subexpr);
            expression.replace(left, len, 1, ans);
        }
        return expression[0] == 't';
    }

private:
    char Evaluate (string s) {
        char op = s[0];
        string vals = s.substr(2, s.size() - 3);
        bool ans;
        if (op == '!')
            ans = vals[0] == 'f';
        else if (op == '&')
            ans = find(vals.begin(), vals.end(), 'f') == vals.end();
        else if (op == '|')
            ans = find(vals.begin(), vals.end(), 't') != vals.end();
        return ans ? 't' : 'f';
    }
};

