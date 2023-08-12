// 2810. Faulty Keyboard
// https://leetcode.com/problems/faulty-keyboard/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string finalString(string s) {
        string ans, tmp;
        size_t prev = 0;
        size_t pos = s.find('i');
        size_t d;
        size_t cnt;
        while (pos != string::npos) {
            d = pos - prev;
            ans += s.substr(prev, d);
            cnt = 1;
            while (pos != string::npos && s[++pos] == 'i')
                ++cnt;
            if (cnt % 2 != 0)
                reverse(ans.begin(), ans.end());
            prev = pos;
            pos = s.find('i', prev);
        }
        if (prev != pos) {
            d = pos - prev;
            ans += s.substr(prev, d);
            reverse(ans.rbegin(), ans.rbegin() + d);
        }
        return ans;
    }
};
