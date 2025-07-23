// 527. Word Abbreviation
// https://leetcode.com/problems/word-abbreviation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's pproach #3: Group + Trie

struct TrieNode {
    vector<TrieNode*> children;
    int count = 0;
    TrieNode(): children(26) {};
};

struct IndexedWord {
    string word;
    int index;
    IndexedWord(string w, int i) {
        word = w;
        index = i;
    }
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, vector<IndexedWord>> groups;
        vector<string> ans(words.size());

        for (int index = 0; index < words.size(); ++index) {
            const string& word = words[index];
            string ab = getAbbr(word, 0);
            groups[ab].emplace_back(word, index);
        }

        for (auto& [_, group]: groups) {
            TrieNode* trie = new TrieNode();
            for (IndexedWord& iw: group) {
                TrieNode* cur = trie;
                for (int j = 1; j < iw.word.size(); ++j) {
                    char ch = iw.word[j];
                    if (cur->children[ch - 'a'] == nullptr)
                        cur->children[ch - 'a'] = new TrieNode();
                    ++cur->count;
                    cur = cur->children[ch - 'a'];
                }
            }

            for (IndexedWord& iw: group) {
                TrieNode* cur = trie;
                int i = 1;
                for (int j = 1; j < iw.word.size(); ++j) {
                    if (cur->count == 1)
                        break;
                    cur = cur->children[iw.word[j] - 'a'];
                    ++i;
                }
                ans[iw.index] = getAbbr(iw.word, i - 1);
            }
        }

        return ans;
    }

private:
    string getAbbr(const string& word, int i) {
        int n = word.size();
        if (n - i <= 3)
            return word;
        return word.substr(0, i + 1) + to_string(n - i - 2) + word[n - 1];
    }
};
