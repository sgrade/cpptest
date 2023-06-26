// 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size();
        int start = 0, end;
        while (start < n) {
            end = min(n, start + k);
            reverse(s.begin() + start, s.begin() + end);
            start += 2 * k;
        }
        return s;
    }
};
