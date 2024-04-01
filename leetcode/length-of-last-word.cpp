// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int pos = s.size() - 1;
        while (s[pos] == ' ')
            --pos;
        int ans = 0;
        while (pos >= 0 && s[pos--] != ' ')
            ++ans;
        return ans;
    }
};
