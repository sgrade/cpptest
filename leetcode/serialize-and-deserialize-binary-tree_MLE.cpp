// 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Memory limit exceeded

#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs_serialize(root, "");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> strings;
        istringstream iss(data);
        string tmp;
        while (getline(iss, tmp, ',')) {
            strings.emplace(tmp);
        }
        return dfs_deserialize(strings);
    }

private:
    string dfs_serialize(TreeNode* node, string s) {
        if (node == nullptr) {
            s += "null,";
            return s;
        }
        s += to_string(node->val) + ',';
        s = dfs_serialize(node->left, s);
        s = dfs_serialize(node->right, s);
        return s;
    }
    
    TreeNode* dfs_deserialize(queue<string> &q) {
        string s = q.front();
        q.pop();
        
        if (s == "null") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = dfs_deserialize(q);
        node->right = dfs_deserialize(q);
        
        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {

    string s = "1,2,3,null,null,4,null,null,5,null,null,";
    Codec c;

    TreeNode* root;
    root = c.deserialize(s);

    string ans;
    ans = c.serialize(root);
    cout << ans << endl;

    return 0;
}
