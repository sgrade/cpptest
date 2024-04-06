// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>

using namespace std;


// Memory Limit Exceeded
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // '(' adds 1, ')' removes 1)
        int parentheses = 0;
        Check (s, 0, "", parentheses);
        return ans;
    }
private:
    string ans;
    void Check (const string& s, int i, string current, int parentheses) {
        if (i >= s.size()) {
            if (parentheses == 0)
                if (current.size() > ans.size())
                    ans = current;
            return;
        }
        char ch = s[i];
        if (ch != '(' && ch != ')')
            Check (s, i + 1, current + ch, parentheses);
        else {
            if (ch == '(') {
                // We can keep or remove
                Check (s, i + 1, current + ch, parentheses + 1);
                Check (s, i + 1, current, parentheses);
            }
            else { // ch == ')'
                if (parentheses == 0) // We can only remove it
                    Check (s, i + 1, current, parentheses);
                else {  // parentheses should be positive
                    --parentheses;
                    Check (s, i + 1, current + ch, parentheses);
                }
            }
        }
    }
};
