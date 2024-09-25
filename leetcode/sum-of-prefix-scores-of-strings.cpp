// 2416. Sum of Prefix Scores of Strings
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

#include <bits/stdc++.h>

using namespace std;


struct TrieNode {
    TrieNode* children[26] = {};
    int prefix_score = 0;
};

class Trie {
public:
    TrieNode* root;

    Trie() {root = new TrieNode;}

    void Insert (string& word) {
        TrieNode* node = root;
        for (char& ch: word) {
            if (node->children[ch - 'a'] == nullptr)
                node->children[ch - 'a'] = new TrieNode();
            ++node->children[ch - 'a']->prefix_score;
            node = node->children[ch - 'a'];
        }
    }

    int GetPrefixScore (string& word) {
        int ans = 0;
        TrieNode* node = root;
        for (char& ch: word) {
            ans += node->children[ch - 'a']->prefix_score;
            node = node->children[ch - 'a'];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); ++i)
            trie->Insert(words[i]);
        vector<int> prefix_scores(words.size());
        for (int i = 0; i < words.size(); ++i)
            prefix_scores[i] = trie->GetPrefixScore(words[i]);
        return prefix_scores;
    }
};
