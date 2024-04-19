// 3114. Latest Time You Can Obtain After Replacing Characters
// https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string findLatestTime(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (i == 2)
                continue;
            if (s[i] == '?') {
                if (i == 0) {
                    if (s[1] == '?') {
                        s[0] = '1';
                        s[1] = '1';
                        continue;
                    }
                    int second_digit = s[1] - '0';
                    if (second_digit > 1)
                        s[i] = '0';
                    else
                        s[i] = '1';
                }
                if (i == 1) {
                    if (s[0] == '0' || s[0] == '?')
                        s[1] = '9';
                    else
                        s[i] = '1';
                }
                if (i == 4)
                    s[i] = '9';
                if (i == 3) {
                    s[i] = '5';
                }
            }
        }
        return s;
    }
};
