// 1704. Determine if String Halves Are Alike
// https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        int i = 0;
        int cnt1 = 0, cnt2 = 0;
        for (; i < n/2; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                ++cnt1;
        }
        for (; i < n; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                ++cnt2;
        }
        return cnt1 == cnt2;
    }
};
