// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <vector>
#include <stack>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        stack<Node*> st;
        st.emplace(root);
        while (!st.empty()) {
            Node* node = st.top();
            ans.emplace_back(node->val);
            st.pop();
            for (std::vector<Node*>::reverse_iterator rit = node->children.rbegin(); rit != node->children.rend(); ++rit) {
                st.emplace(*rit);
            }
        }
        return ans;
    }
};
