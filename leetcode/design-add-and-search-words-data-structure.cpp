// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <bits/stdc++.h>

using namespace std;


// Some ideas are from 
// https://leetcode.com/problems/design-add-and-search-words-data-structure/discuss/866767/C%2B%2B-Trie-%2B-DFS-solution.-Detailed-Explanation
// https://leetcode.com/problems/design-add-and-search-words-data-structure/discuss/1524723/Trie-explained-line-by-line-C%2B%2B

struct TrieNode {
    vector<TrieNode*> children;
    bool is_end_of_word = false;
    TrieNode(): children(26) {};
};


class WordDictionary {
public:   
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = trie;
        for (const char &c: word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->is_end_of_word = true;
    }
    
    bool search(string word) {
        return check(trie, word, 0);
    }

private:
    TrieNode* trie;
    
    bool check(TrieNode* node, const string& word, const int& index) {
        if (index == word.size()) {
            return node->is_end_of_word;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && check(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        }
        else {
            node = node->children[word[index] - 'a'];
            return node && check(node, word, index + 1);   
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
