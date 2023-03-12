// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>

using namespace std;


// SLOW
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> chars;
        unordered_set<char> values;
        char ch;
        for (int i = 0; i < s.size(); ++i) {
            if (chars.find(s[i]) != chars.end()) {
                if (t[i] != chars[s[i]]) 
                    return false;
            }
            else
                if (values.find(t[i]) != values.end())
                    return false;
                chars[s[i]] = t[i];
                values.emplace(t[i]);
        }
        return true;
    }
};
