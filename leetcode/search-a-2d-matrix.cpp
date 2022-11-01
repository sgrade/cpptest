// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (matrix[0][0] > target || matrix[rows - 1][cols - 1] < target) {
            return false;
        }
        
        int target_row, target_col;
        
        int left = 0, right = rows - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[mid][0] <= target && matrix[mid][cols - 1] >= target) {
                target_row = mid;
                break;
            }
            else if (matrix[mid][0] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

        }
        
        left = 0, right = cols - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[target_row][mid] == target) {
                return true;
            }
            else if (matrix[target_row][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
