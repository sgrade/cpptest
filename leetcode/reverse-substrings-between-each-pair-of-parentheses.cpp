// 1190. Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int> indexes;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                indexes.emplace(ans.size());
            else if (s[i] == ')') {
                int left = indexes.top();
                indexes.pop();
                if (left != ans.size())
                    reverse(ans.begin() + left, ans.end());
            }
            else
                ans += s[i];
        }
        return ans;
    }
};
