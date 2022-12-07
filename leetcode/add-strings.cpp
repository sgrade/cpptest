// 415. Add Strings
// https://leetcode.com/problems/add-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        if (n1 < n2) {
            swap (num1, num2);
        }
        int mn = min(n1, n2), mx = max(n1, n2);

        string rev_ans;
        int current, carry = 0;
        for (int i = 1; i <= mn; ++i) {
            current = carry + (num1[mx - i] - '0') + (num2[mn - i] - '0');
            carry = current >= 10 ? 1 : 0;
            rev_ans += to_string(current % 10);
        }
        for (int i = mx - mn - 1; i >= 0; --i) {
            current = carry + (num1[i] - '0');
            carry = current >= 10 ? 1 : 0;
            rev_ans += to_string(current % 10);
        }
        if (carry) {
            rev_ans += "1";
        }
        reverse(rev_ans.begin(), rev_ans.end());
        return rev_ans;
    }
};
