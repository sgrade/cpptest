// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Shortened Two Pass String Builder
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // '(' adds 1, ')' removes 1)
        int balance = 0, open = 0;
        string first_pass = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++open;
                ++balance;
            }
            else if (s[i] == ')') {
                if (balance == 0)
                    continue;
                --balance;
            }
            first_pass += s[i];
        }

        if (balance == 0)
            return first_pass;

        string ans = "";
        int open_to_keep = open - balance;
        for (int i = 0; i < first_pass.size(); ++i) {
            if (first_pass[i] == '(') {
                --open_to_keep;
                if (open_to_keep < 0)
                    continue;
            }
            ans += first_pass[i];
        }
        return ans;
    }
};
