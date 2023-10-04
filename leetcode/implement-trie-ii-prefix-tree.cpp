// 1804. Implement Trie II (Prefix Tree)
// https://leetcode.com/problems/implement-trie-ii-prefix-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial

class TrieNode {
public:
    TrieNode () {
        children.resize(26);
    }
    vector<TrieNode*> children;
    int words_start_here = 0;
    int words_end_here = 0;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char& ch: word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            ++node->words_start_here;
        }
        ++node->words_end_here;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (const char& ch: word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return 0;
            node = node->children[idx];
        }
        return node->words_end_here;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (const char& ch: prefix) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return 0;
            node = node->children[idx];
        }
        return node->words_start_here;
    }
    
    void erase(string word) {
        TrieNode* node = root;
        for (char& ch: word) {
            int idx = ch - 'a';
            node = node->children[idx];
            --node->words_start_here;
        }
        --node->words_end_here;
    }

private:
    TrieNode* root;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
