// 500. Keyboard Row
// https://leetcode.com/problems/keyboard-row/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<unordered_set<char>> sets = {
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}, 
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}, 
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
        };
        for (const string& word: words) {
            char first = tolower(word[0]);
            for (auto& st: sets) {
                if (st.find(first) != st.end()) {
                    if (CanBeTypedWithOneRow (st, word))
                        ans.emplace_back(word);
                    break;
                }
            }
        }
        return ans;
    }
private:
    bool CanBeTypedWithOneRow (unordered_set<char>& st, const string& word) {
        for (size_t i = 1; i < word.size(); ++i) {
            if (st.find(tolower(word[i])) == st.end())
                return false;
        }
        return true;
    }
};
