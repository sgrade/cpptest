// 1119. Remove Vowels from a String
// https://leetcode.com/problems/remove-vowels-from-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for (const char& ch: s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                continue;
            ans += ch;
        }
        return ans;
    }
};
