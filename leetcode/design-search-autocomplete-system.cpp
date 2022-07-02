// 642. Design Search Autocomplete System
// https://leetcode.com/problems/design-search-autocomplete-system/

#include <bits/stdc++.h>

using namespace std;


struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string s;
    int times;
    TrieNode () {
        s = "";
        times = 0;
    }
};

// Comparator for the max_heap
struct comp{
    bool operator() (pair<string, int>& a, pair<string, int>& b){
        return a.second < b.second || a.second == b.second && a.first > b.first;
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root_ = new TrieNode();
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], root_, times[i]);
        }
        cur_ = root_;
        s_ = "";
    }
    
    vector<string> input(char c) {
        // priority_queue has no clear() method
        max_heap = priority_queue<pair<string, int>, vector<pair<string, int>>, comp>();
        
        if (c == '#') {
            insert(s_, root_, 1);
            s_ = "";
            cur_ = root_;
            return {};
        }
        
        s_ += c;
        if (cur_ && cur_->children.find(c) != cur_->children.end()) {
            cur_ = cur_->children[c];
        }
        else {
            cur_ = nullptr;
            return {};
        }
        
        if (cur_->s != "") {
            max_heap.push({cur_->s, cur_->times});
        }
        for (auto &[ch, trie_node]: cur_->children) {
            dfs(trie_node);
        }
        
        vector<string> ans;
        while (!max_heap.empty() && ans.size() < 3) {
            ans.emplace_back(max_heap.top().first);
            max_heap.pop();
        }
        
        return ans;
    }
    
    void dfs(TrieNode* temp) {
        if (temp->s != "") {
            max_heap.emplace(pair<string, int>(temp->s, temp->times));
        }
        for (auto &[ch, trie_node]: temp->children) {
            dfs(trie_node);
        }
    }
    
private:
    TrieNode *root_, *cur_;
    string s_;
    // What to store, container, comparator
    priority_queue<pair<string, int>, vector<pair<string, int> >, comp> max_heap;
    
    void insert(string &s, TrieNode* node, int times) {
        TrieNode *cur = node;
        for (int i = 0; i < s.size(); ++i) {
            if (!cur->children[s[i]]) {
                cur->children[s[i]] = new TrieNode();
            }
            cur = cur -> children[s[i]];
        }
        cur -> times += times;
        cur -> s = s;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
 