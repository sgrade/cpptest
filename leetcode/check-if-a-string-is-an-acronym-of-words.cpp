// 2828. Check if a String Is an Acronym of Words
// https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int idx1 = 0, n1 = words.size(), idx2 = 0, n2 = s.size();
        if (n1 != n2)
            return false;
        while (idx1 < n1) {
            if (words[idx1++][0] != s[idx2++])
                return false;
        }
        return true;
    }
};
