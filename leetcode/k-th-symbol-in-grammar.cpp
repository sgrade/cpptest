// 779. K-th Symbol in Grammar
// https://leetcode.com/problems/k-th-symbol-in-grammar/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Binary Tree Traversal
class Solution {
public:
    int kthGrammar(int n, int k) {
        this->n = n;
        return dfs(k, 0);
    }
private:
    int n;
    int dfs(int k, int root_val) {
        if (n == 1)
            return root_val;
        int nodes = pow(2, n - 1);
        --n;
        if (k > nodes / 2) {
            int next_root_val = (root_val == 0) ? 1 : 0;
            return dfs(k - nodes / 2, next_root_val);
        }
        else {
            int next_root_val = (root_val == 0) ? 0 : 1;
            return dfs(k, next_root_val);
        }
    }
};
