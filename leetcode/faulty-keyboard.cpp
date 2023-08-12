// 2810. Faulty Keyboard
// https://leetcode.com/problems/faulty-keyboard/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'i')
                ans += s[i];
            else {
                int cnt = 1;
                while (i + cnt != n && s[i + cnt] == 'i')
                    ++cnt;
                if (cnt % 2 != 0)
                    reverse(ans.begin(), ans.end());
                i += cnt - 1;
            }
        }
        return ans;
    }
};
