// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <bits/stdc++.h>

using namespace std;


// Based on a Leetcode's Sample 485 ms submission
class WordDictionary {
public:
    WordDictionary(): words_by_size(26) {}
    
    void addWord(string word) {
        words_by_size[word.size()].emplace(word);
    }
    
    bool search(string word) {
        size_t n = word.size();
        const unordered_set<string>& set = words_by_size[n];
        if (word.find('.') == string::npos) 
            return set.find(word) != set.end();
        bool found;
        for (const string& s: set) {
            found = true;
            for (size_t i = 0; i < n; ++i) {
                if (word[i] == '.') continue;
                if (word[i] != s[i]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        return false;
    }

private: 
    vector<unordered_set<string>> words_by_size;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
