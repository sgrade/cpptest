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


// Based on Leetcode's Approach 1: Recursion
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return ConstructNode (grid, 0, 0, grid.size());
    }

private:
    Node* ConstructNode (vector<vector<int>>& grid, int x1, int y1, int len) {

        Node* node = new Node();

        if (IsLeaf(grid, x1, y1, len)) {
            node->val = grid[x1][y1] == 1 ? true : false;
            node->isLeaf = true;
        }
        
        else {
            len /= 2;
            node->topLeft = ConstructNode (grid, x1, y1, len);
            node->topRight = ConstructNode (grid, x1, y1 + len, len);
            node->bottomLeft = ConstructNode (grid, x1 + len, y1, len);
            node->bottomRight = ConstructNode (grid, x1 + len, y1 + len, len);
        }

        return node;
    }

    bool IsLeaf (vector<vector<int>>& grid, int x1, int y1, int len) {
        int val = grid[x1][y1];
        for (int x = x1; x < x1 + len; ++x) {
            for (int y = y1; y < y1 + len; ++y) {
                if (grid[x][y] != val) return false;
            }
        }
        return true;
    }
};
