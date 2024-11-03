// 796. Rotate String
// https://leetcode.com/problems/rotate-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (int i = 0; i < s.size(); ++i) {
            if (s == goal)
                return true;
            char ch = s.back();
            s.pop_back();
            s = ch + s;
        }
        return false;
    }
};
