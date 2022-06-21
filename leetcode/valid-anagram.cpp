// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() < t.size()) {
            return isAnagram (t, s);
        }
        unordered_map<char, int> counter_s, counter_t;
        for (char &c: s) {
            ++counter_s[c];
        }
        for (char &c: t) {
            ++counter_t[c];
        }
        bool ans = true;
        for (auto const& [key, value]: counter_s) {
            if (counter_t[key] != value) {
                ans = false;
                break;
            }
        }
        return ans ? true : false;
    }
};
