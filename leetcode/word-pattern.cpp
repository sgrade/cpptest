// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream ss(s);
        string word;
        while (ss >> word) {
            words.emplace_back(word);
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> bijection;
        unordered_set<string> met;
        char ch;
        for (int i = 0; i < pattern.size(); ++i) {
            ch = pattern[i];
            if (bijection.find(ch) == bijection.end()) {
                if (met.find(words[i]) != met.end()) {
                    return false;
                }
                bijection[ch] = words[i];
                met.emplace(words[i]);
            }
            else {
                if (bijection[ch] != words[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
