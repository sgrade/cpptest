// 2696. Minimum String Length After Removing Substrings
// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minLength(string s) {
        while (!s.empty()) {
            bool repeat = false;
            for (int i = 1; i < s.size(); ++i) {
                if ((s[i - 1] == 'A' && s[i] == 'B') ||
                    (s[i - 1] == 'C' && s[i] == 'D')
                ) {
                    s.erase (i - 1, 2);
                    repeat = true;
                    break;
                }
            }
            if (!repeat)
                break;
        }
        return s.size();
    }
};
