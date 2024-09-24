// 3043. Find the Length of the Longest Common Prefix
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

#include <bits/stdc++.h>

using namespace std;


class TrieNode {
public:
    vector<TrieNode*> children;
    bool end_of_word = false;
    TrieNode() : children(10) {}
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void Insert(int num) {
        stack<int> digits = NumToDigits(num);
        TrieNode* node = root;
        while (!digits.empty()) {
            int current = digits.top();
            digits.pop();
            if (!node->children[current])
                node->children[current] = new TrieNode();
            node = node->children[current];
        }
        node->end_of_word = true;
    }

    int GetCommonPrefixLen(int num) {
        int len = 0;
        stack<int> digits = NumToDigits(num);
        TrieNode* node = root;
        while (!digits.empty()) {
            int current = digits.top();
            digits.pop();
            if (!node->children[current])
                break;
            ++len;
            node = node->children[current];
        }
        return len;
    }

    stack<int> NumToDigits(int& num) {
        stack<int> digits;
        while (num) {
            digits.emplace(num % 10);
            num /= 10;
        }
        return digits;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        Trie* trie = new Trie();
        for (const int& num: arr1)
            trie->Insert(num);
        int ans = 0;
        for (const int& num: arr2) {
            int current_ans = trie->GetCommonPrefixLen(num);
            ans = max(ans, current_ans);
        }
        return ans;
    }
};
