// 1948. Delete Duplicate Folders in System
// https://leetcode.com/problems/delete-duplicate-folders-in-system/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Serialization-Based Representation of Subtrees
class Trie {
public:
    string serial;
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        Trie* root = new Trie();
        for (const vector<string>& path: paths) {
            Trie* cur = root;
            for (const string& node: path) {
                if (!cur->children.count(node))
                    cur->children[node] = new Trie();
                cur = cur->children[node];
            }
        }

        construct(root);
        operate(root);
        return ans;
    }

private:
    unordered_map<string, int> counter;
    vector<string> path;
    vector<vector<string>> ans;

    void construct(Trie* node) {
        if (node->children.empty())
            return;
        vector<string> serials;
        for (const auto& [folder, child]: node->children) {
            construct(child);
            serials.emplace_back(folder + "(" + child->serial + ")");
        }
        sort(serials.begin(), serials.end());
        for (string& s: serials)
            node->serial += move(s);
        ++counter[node->serial];
    }

    void operate(Trie* node) {
        if (counter[node->serial] > 1)
            return;
        if (!path.empty())
            ans.emplace_back(path);
        for (const auto& [folder, child]: node->children) {
            path.emplace_back(folder);
            operate(child);
            path.pop_back();
        }
    }
};
