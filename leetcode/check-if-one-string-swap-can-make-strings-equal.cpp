// 1790. Check if One String Swap Can Make Strings Equal
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int idx = 0;
        vector<int> indexes(2, -1);
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (idx == 2)
                    return false;
                indexes[idx++] = i;
            }
        }
        if (idx == 0)
            return true;
        else if (idx == 1)
            return false;
        return s1[indexes[0]] == s2[indexes[1]] && s1[indexes[1]] == s2[indexes[0]];
    }
};
