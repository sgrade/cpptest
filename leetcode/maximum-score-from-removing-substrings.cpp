// 1717. Maximum Score From Removing Substrings
// https://leetcode.com/problems/maximum-score-from-removing-substrings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        string pattern, anti_pattern;
        if (x > y) {
            pattern = "ab";
            anti_pattern = "ba";
        }
        else {
            pattern = "ba";
            anti_pattern = "ab";
            swap (x, y);
        }

        int pos = 0;
        while (pos != string::npos) {
            pos = s.find(pattern, pos);
            if (pos == string::npos)
                break;
            s.erase(pos, 2);
            ans += x;
            pos = max(0, pos - 1);
        }

        pos = 0;
        while (pos != string::npos) {
            pos = s.find(anti_pattern, pos);
            if (pos == string::npos)
                break;
            s.erase(pos, 2);
            ans += y;
            pos = max(0, pos - 1);
        }

        return ans;
    }
};
