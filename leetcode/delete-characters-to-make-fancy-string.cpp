// 1957. Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string ans;
        for (const char& ch: s) {
            if (ans.size() > 1 && ch == ans[ans.size() - 2] && ch == ans[ans.size() - 1]) continue;
            ans += ch;
        }
        return ans;
    }
};
