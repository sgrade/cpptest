// 3110. Score of a String
// https://leetcode.com/problems/score-of-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i)
            ans += abs(s[i] - s[i - 1]);
        return ans;
    }
};
