// 2785. Sort Vowels in a String
// https://leetcode.com/problems/sort-vowels-in-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string sortVowels(string s) {
        vector<char> chars;
        queue<int> indexes;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                chars.emplace_back(s[i]);
                indexes.emplace(i);
            }
        }
        sort(chars.begin(), chars.end());
        int i;
        for (const char& ch: chars) {
            i = indexes.front();
            indexes.pop();
            s[i] = ch;
        }
        return s;
    }
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};
