// 2416. Sum of Prefix Scores of Strings
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

#include <bits/stdc++.h>

using namespace std;


// Memory Limit Exceeded
// 36 / 38 testcases passed

struct TrieNode {
    vector<TrieNode*> children;
    vector<int> prefix_score;
    TrieNode() : children(26), prefix_score(26) {};
};

class Trie {
public:
    TrieNode* root;

    Trie() {root = new TrieNode;}

    void Insert (const string& word) {
        TrieNode* node = root;
        for (const char& ch: word) {
            int i = ch - 'a';
            ++node->prefix_score[i];
            if (node->children[i] == nullptr)
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
    }

    int GetPrefixScore (const string& word) {
        int ans = 0;
        TrieNode* node = root;
        for (const char& ch: word) {
            int i = ch - 'a';
            ans += node->prefix_score[i];
            node = node->children[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        Trie* trie = new Trie();
        for (const string& word: words)
            trie->Insert(word);
        vector<int> prefix_scores;
        for (const string& word: words) {
            int score = trie->GetPrefixScore(word);
            prefix_scores.emplace_back(score);
        }
        return prefix_scores;
    }
};
