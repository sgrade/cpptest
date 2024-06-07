// 648. Replace Words
// https://leetcode.com/problems/replace-words/

#include <bits/stdc++.h>

using namespace std;


// Used some hints from Editorial's Approach 2: Prefix Trie
class TrieNode {
public:
    vector<TrieNode*> children;
    bool end_of_word = false;
    TrieNode() : children(26, nullptr) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        int idx;
        for (const auto &ch: word) {
            idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->end_of_word = true;
    }

    string search(string word) {
        TrieNode* node = root;
        int idx;
        for (int i = 0; i < word.size(); ++i) {
            idx = word[i] - 'a';
            if (!node->children[idx]) {
                return word;
            }
            node = node->children[idx];
            if (node->end_of_word)
                return word.substr(0, i + 1);
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        Trie* trie = new Trie();
        for (const string& word: dictionary)
            trie->insert(word);

        string ans;
        string word;
        istringstream iss(sentence);
        while (getline(iss, word, ' '))
            ans += trie->search(word) + " ";
        ans.pop_back();
        return ans;
    }
};
