// 422. Valid Word Square
// https://leetcode.com/problems/valid-word-square/

#include <bits/stdc++.h>

using namespace std;


// Used ideas from Leetcode's Approach 2: Iterate on the Matrix
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        size_t rows = words.size(), cols;
        for (size_t row = 0; row < rows; ++row) {
            cols = words[row].size();
            for (size_t col = 0; col < cols; ++col) {
                if (col >= rows || row >= words[col].size() || words[row][col] != words[col][row])
                    return false;
            }
        }
        return true;
    }
};
