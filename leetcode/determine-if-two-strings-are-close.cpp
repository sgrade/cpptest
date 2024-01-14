// 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cntr1(26), cntr2(26);
        for (const char& ch: word1)
            ++cntr1[ch - 'a'];
        for (const char& ch: word2)
            ++cntr2[ch - 'a'];
        for (int i = 0; i < 26; ++i)
            if ((cntr1[i] == 0 && cntr2[i] != 0) || (cntr2[i] == 0 && cntr1[i] != 0))
                return false;
        sort(cntr1.begin(), cntr1.end());
        sort(cntr2.begin(), cntr2.end());
        return cntr1 == cntr2;
    }
};
