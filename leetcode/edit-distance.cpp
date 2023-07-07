// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursion
// TLE
class Solution {
public:
    int minDistance(string word1, string word2) {
        return traverse(word1, word2, word1.size(), word2.size());
    }

private:
    int traverse (string& word1, string& word2, int idx1, int idx2) {
        if (idx1 == 0)
            return idx2;
        if (idx2 == 0)
            return idx1;
        if (word1[idx1 - 1] == word2[idx2 - 1])
            return traverse(word1, word2, idx1 - 1, idx2 - 1);
        else {
            int insert_operation, delete_operation, replace_operation;
            insert_operation = traverse(word1, word2, idx1, idx2 - 1);
            delete_operation = traverse(word1, word2, idx1 - 1, idx2);
            replace_operation = traverse(word1, word2, idx1 - 1, idx2 - 1);
            return min({insert_operation, delete_operation, replace_operation}) + 1;
        }
    }
};
