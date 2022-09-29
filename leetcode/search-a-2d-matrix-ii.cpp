// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        int current;
        while (row < matrix.size() && col >= 0) {
            current = matrix[row][col];
            if (current == target) {
                return true;
            }
            else if (current > target) {
                --col;
            }
            else {
                ++row;
            }
        }
        return false;
    }
};
