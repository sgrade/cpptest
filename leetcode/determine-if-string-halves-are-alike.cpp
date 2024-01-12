// 1704. Determine if String Halves Are Alike
// https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_map<char, int> h1, h2;
        int i = 0;
        for (; i < n/2; ++i)
            ++h1[s[i]];
        for (; i < n; ++i)
            ++h2[s[i]];
        int cnt1 = 0, cnt2 = 0;
        for (const char& ch: vowels) {
            cnt1 += h1[ch];
            cnt2 += h2[ch];
        }
        return cnt1 == cnt2;
    }
private:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};
