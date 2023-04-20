// 1166. Design File System
// https://leetcode.com/problems/design-file-system/

#include <bits/stdc++.h>

using namespace std;


struct TrieNode {
    unordered_map<string, TrieNode*> children;
    bool is_end_of_path = false;
    int val = -1;
};

class FileSystem {
public:
    FileSystem() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        root = new TrieNode();
    }
    
    bool createPath(string path, int value) {
        TrieNode* node = root;
        vector<string> chunks = split (path);
        int i = 0;
        for (; i < chunks.size() - 1; ++i) {
            if (node->children.find(chunks[i]) == node->children.end())
                return false;
            node = node->children[chunks[i]];
        }
        if (node->children.find(chunks[i]) != node->children.end())
            return false;
        TrieNode* child = new TrieNode();
        child->val = value;
        node->children[chunks[i]] = child;
        return true;
    }
    
    int get(string path) {
        TrieNode* node = root;
        vector<string> chunks = split (path);
        for (int i = 0; i < chunks.size(); ++i) {
            if (node->children.find(chunks[i]) == node->children.end())
                return -1;
            node = node->children[chunks[i]];
        }
        return node->val;
    }

    vector<string> split (const string& path) {
        vector<string> output;
        int left = 1, right;
        while (left < path.size()) {
            right = path.find('/', left);
            if (right == string::npos)
                right = path.size();
            string chunk = path.substr(left, right - left);
            output.emplace_back(chunk);
            left = right + 1;
        }
        return output;
    }

private:
    TrieNode* root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
