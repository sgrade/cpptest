// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];
        for (const char& ch: t)
            --counter[ch - 'a'];
        for (const int& cnt: counter)
            if (cnt != 0)
                return false;
        return true;
    }
};
