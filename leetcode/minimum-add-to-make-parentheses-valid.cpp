// 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minAddToMakeValid(string s) {
        ios::sync_with_stdio;
        cin.tie(nullptr);

        int ans = 0, open = 0;
        for (const char& ch: s) {
            if (ch == '(')
                ++open;
            else {
                if (open == 0)
                    ++ans;
                else
                    --open;
            }
        }
        ans += open;
        return ans;
    }
};
