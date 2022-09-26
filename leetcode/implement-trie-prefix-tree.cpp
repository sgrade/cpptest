// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>

using namespace std;


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
    
    bool search(string word) {
        TrieNode* node = root;
        int idx;
        for (const auto &ch: word) {
            idx = ch - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
        }
        return node->end_of_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int idx = 0;
        for (const auto &ch: prefix) {
            idx = ch - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
