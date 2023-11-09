// 1759. Count Number of Homogenous Substrings
// https://leetcode.com/problems/count-number-of-homogenous-substrings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countHomogenous(string s) {
        int ans = 1, cnt = 1, MOD = 1e9 + 7;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1])
                ++cnt;
            else
                cnt = 1;
            ans += cnt;
            ans %= MOD;
        }
        return ans;
    }
};
