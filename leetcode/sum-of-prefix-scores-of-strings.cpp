// 2416. Sum of Prefix Scores of Strings
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

#include <bits/stdc++.h>

using namespace std;


// Memory Limit Exceeded
// 38 / 38 testcases passed

struct TrieNode {
    vector<TrieNode*> children;
    int prefix_score = 0;
    TrieNode() : children(26) {};
};

class Trie {
public:
    TrieNode* root;

    Trie() {root = new TrieNode;}

    void Insert (const string& word) {
        TrieNode* node = root;
        for (const char& ch: word) {
            int i = ch - 'a';
            if (node->children[i] == nullptr)
                node->children[i] = new TrieNode();
            ++node->children[i]->prefix_score;
            node = node->children[i];
        }
    }

    int GetPrefixScore (const string& word) {
        int ans = 0;
        TrieNode* node = root;
        for (const char& ch: word) {
            int i = ch - 'a';
            ans += node->children[i]->prefix_score;
            node = node->children[i];
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
