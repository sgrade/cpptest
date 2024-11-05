// 2914. Minimum Number of Changes to Make Binary String Beautiful
// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minChanges(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        for (int i = 1; i < s.size(); i += 2) {
            if (s[i] != s[i - 1])
                ++ans;
        }
        return ans;
    }
};
