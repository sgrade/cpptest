// 1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, current_ans = 0;
        for (const char& ch: s) {
            if (ch == '(') {
                ++current_ans;
                ans = max(ans, current_ans);
            }
            else if (ch == ')')
                --current_ans;
        }
        return ans;
    }
};
