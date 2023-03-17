// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>

using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// NOT FINISHED
class TrieNode {
public:
    TrieNode() : children(26, nullptr) {}
    bool ContainsKey(char ch) {
        return children[ch - 'a'];
    }
    TrieNode* Get(char ch) {
        return children[ch - 'a'];
    }
    void Put(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }
    void SetEnd() {
        is_end = true;
    }
    bool IsEnd() {
        return is_end;
    }
private:
    vector<TrieNode*> children(26, nullptr);
    bool is_end;
};


class Trie {
public:    
    void insert(string word) {
        TrieNode* node = root;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!node->ContainsKey(word[i])) {
                node->Put(word[i], new TrieNode());
            }
            node = node->Get(word[i]);
        }
        node->SetEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (size_t i = 0; i < word.size(); ++i) {
            if (node->ContainsKey(word[i])) {
                node = node->Get(word[i]);
            }
            else {
                return false;
            }
        }
        return node->IsEnd();
    }
    
    bool startsWith(string prefix) {
        return search(prefix);
    }

private:
    TrieNode* root = new TrieNode();
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */