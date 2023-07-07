// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Memoization: Top-Down Dynamic Programming
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));
        return traverse(word1, word2, n1, n2, memo);
    }

private:
    int traverse (string& word1, string& word2, int idx1, int idx2, vector<vector<int>>& memo) {
        if (idx1 == 0)
            return idx2;
        if (idx2 == 0)
            return idx1;
        if (memo[idx1][idx2] != -1)
            return memo[idx1][idx2];
        if (word1[idx1 - 1] == word2[idx2 - 1])
            return traverse(word1, word2, idx1 - 1, idx2 - 1, memo);
        else {
            int insert_operation, delete_operation, replace_operation;
            insert_operation = traverse(word1, word2, idx1, idx2 - 1, memo);
            delete_operation = traverse(word1, word2, idx1 - 1, idx2, memo);
            replace_operation = traverse(word1, word2, idx1 - 1, idx2 - 1, memo);
            return memo[idx1][idx2] = min({insert_operation, delete_operation, replace_operation}) + 1;
        }
    }
};
