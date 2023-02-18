// 288. Unique Word Abbreviation
// https://leetcode.com/problems/unique-word-abbreviation/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/unique-word-abbreviation/solutions/73133/8-lines-in-c/
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        string abbr;
        for (const string& s: dictionary) {
            abbr = GetAbbr (s);
            abbreviations_to_words[abbr].emplace(s);
        }
    }
    
    bool isUnique(string word) {
        string abbr = GetAbbr(word);
        return abbreviations_to_words[abbr].count(word) == abbreviations_to_words[abbr].size();
    }
private:
    unordered_map<string, unordered_set<string>> abbreviations_to_words;
    string GetAbbr (const string& s) {
        return s[0] + to_string(s.size()) + s[s.size() - 1];
    }
};


vector<string> dictionary;
string word;
// Your ValidWordAbbr object will be instantiated and called as such:
ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
bool param_1 = obj->isUnique(word);

