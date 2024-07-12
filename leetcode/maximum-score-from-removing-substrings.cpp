// 1717. Maximum Score From Removing Substrings
// https://leetcode.com/problems/maximum-score-from-removing-substrings/

#include <bits/stdc++.h>

using namespace std;


// TLE
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

        while (true) {
            int pos = 0;
            while (pos != string::npos) {
                pos = s.find(pattern, pos);
                if (pos != string::npos) {
                    s.erase(pos, 2);
                    ans += x;
                    pos = max (0, pos - 1);
                }
            }
            pos = s.find(anti_pattern);
            if (pos != string::npos) {
                s.erase(pos, 2);
                ans += y;
            }
            else
                break;
        }

        return ans;
    }
};
