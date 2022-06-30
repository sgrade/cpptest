// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int cnt_s = 0, cnt_t = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    ++cnt_s;
                    --i;
                }
                else if (cnt_s > 0) {
                    --cnt_s;
                    --i;
                }
                else break;
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    ++cnt_t;
                    --j;
                }
                else if (cnt_t > 0) {
                    --cnt_t;
                    --j;
                }
                else break;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            --i;
            --j;
        }
        return true;
    }
};
