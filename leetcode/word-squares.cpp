// 425. Word Squares
// https://leetcode.com/problems/word-squares/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 1: Backtracking with HashTable
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        rows = words.size(), cols = words[0].size();

        for (const string& word: words) {
            for (int col = 1; col < cols; ++col) {
                string prefix = word.substr(0, col);
                vector<string>& cur = prefix_to_words[prefix];
                if (cur.empty())
                    prefix_to_words[prefix] = {word};
                else
                    prefix_to_words[prefix].emplace_back(word);
            }
        }

        for (const string& word: words) {
            vector<string> word_squares = {word};
            backtrack(1, word_squares);
        }

        return ans;
    }

private:
    int rows, cols;
    unordered_map<string, vector<string>> prefix_to_words;
    vector<vector<string>> ans;

    void backtrack(int idx, vector<string>& word_squares) {
        if (idx == cols) {
            ans.emplace_back(word_squares);
            return;
        }

        string prefix;
        for (const string word: word_squares)
            prefix += word[idx];
        
        for (const string& candidate: prefix_to_words[prefix]) {
            word_squares.emplace_back(candidate);
            backtrack(idx + 1, word_squares);
            word_squares.pop_back();
        }
    }
};
