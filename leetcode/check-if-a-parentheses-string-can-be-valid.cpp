// 2116. Check if a Parentheses String Can Be Valid
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Editorial's Approach 2: Constant Space
class Solution {
public:
    bool canBeValid(string s, string locked) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size();
        if (n % 2 != 0)
            return false;

        int open_locked = 0, unlocked = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                ++unlocked;
                continue;
            }
            char ch = s[i];
            if (ch == '(')
                ++open_locked;
            else {
                if (open_locked > 0)
                    --open_locked;
                else if (unlocked > 0)
                    --unlocked;
                else
                    return false;
            }
        }

        int balance = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                --balance;
                --unlocked;
            }
            else if (s[i] == '(') {
                ++balance;
                --open_locked;
            }
            else if (s[i] == ')')
                --balance;

            if (balance > 0)
                return false;
            if (unlocked == 0 && open_locked == 0)
                break;
        }

        if (open_locked > 0)
            return false;

        return true;
    }
};
