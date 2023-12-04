// 2264. Largest 3-Same-Digit Number in String
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 2; i < num.size(); ++i) {
            if (num[i] == num[i - 1] && num[i - 1] == num [i - 2])
                ans = max(ans, num.substr(i - 2, 3));
        }
        return ans;
    }
};
