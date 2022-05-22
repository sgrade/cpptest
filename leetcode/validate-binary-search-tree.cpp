// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode* tn, long long left, long long right) {
    
    if (!tn) return true;
    
    if (!(tn->val < left && tn->val > right)) return false;
    
    return check(tn->left, left, tn->val) && (tn->right, tn->val, left);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
};

int main(){
    
}
