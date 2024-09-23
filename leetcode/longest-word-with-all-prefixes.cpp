// 1858. Longest Word With All Prefixes
// https://leetcode.com/problems/longest-word-with-all-prefixes/

#include <bits/stdc++.h>

using namespace std;


struct TrieNode {
    vector<TrieNode*> children;
    bool end_of_word = false;
    TrieNode() : children(26) {};
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void Insert(string word) {
        TrieNode* node = root;
        for (const char& ch: word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->end_of_word = true;
    }

    string Dfs() {
        string ans = "";
        queue<pair<TrieNode*, string>> q;
        q.emplace(root, "");
        while (!q.empty()) {
            auto [node, prev_ans] = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i) {
                TrieNode* child = node->children[i];
                if (child == nullptr || !child->end_of_word)
                    continue;
                string current_ans = prev_ans;
                current_ans += 'a' + i;
                if (current_ans.size() > ans.size())
                    ans = current_ans;
                q.emplace(child, current_ans);
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie;
        for (const string& word: words)
            trie->Insert(word);
        string ans = trie->Dfs();
        return ans;
    }
};
