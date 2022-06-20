// 161. One Edit Distance
// https://leetcode.com/problems/one-edit-distance/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        int cnt;
        if (n - m > 1) return false;
        if (n == m) {
            cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    ++cnt;
                }
            }
            if (cnt == 0 || cnt > 1) {
                return false;
            }
        }
        else {
            if (n < m) {
                return isOneEditDistance(t, s);
            }
            cnt = 0;
            int j = 0;
            for (int i = 0; i < n, j < m;) {
                if (s[i] != t[j]) {
                    cnt += 1;
                    if (cnt > 1) break;
                    ++i;
                }
                else {
                    ++i;
                    ++j;
                }
            }
            if (cnt > 1) {
                return false;
            }
        }
        return true;
    }
};
