// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        if (s[0] == '0') {
            return 0;
        }
        else {
            dp[1] = 1;
        }
        for (int i = 2; i < n + 1; ++i) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            int cur = stoi(s.substr(i - 2, 2));
            if (cur >= 10 && cur <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
