// 427. Construct Quad Tree
// https://leetcode.com/problems/construct-quad-tree/

#include <bits/stdc++.h>

using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


// Based on Leetcode's Approach 2: Optimized Recursion
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return ConstructNode (grid, 0, 0, grid.size());
    }

private:
    Node* ConstructNode (vector<vector<int>>& grid, int x1, int y1, int len) {

        if (len == 1)
            return new Node(grid[x1][y1], true);

        len /= 2;
        Node* topLeft = ConstructNode (grid, x1, y1, len);
        Node* topRight = ConstructNode (grid, x1, y1 + len, len);
        Node* bottomLeft = ConstructNode (grid, x1 + len, y1, len);
        Node* bottomRight = ConstructNode (grid, x1 + len, y1 + len, len);

        bool is_leaf = topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf;
        int val = topLeft->val;
        bool same_value = topRight->val == val && bottomLeft->val == val && bottomRight->val == val;
        
        if (is_leaf && same_value) 
            return new Node(val, true);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
