// 1428. Leftmost Column with at Least a One
// https://leetcode.com/problems/leftmost-column-with-at-least-a-one/

#include <bits/stdc++.h>

using namespace std;


// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
  public:
    int get(int row, int col);
    vector<int> dimensions();
};


class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int ans = 128, current_ans;
        for (int row = 0; row < dimensions[0]; ++row) {
            current_ans = GetColumn(binaryMatrix, row, dimensions[1]);
            if (current_ans != -1) {
                ans = min(ans, current_ans);
            }
        }
        return (ans == 128 ? -1 : ans);
    }
private:
    int GetColumn (BinaryMatrix &binaryMatrix, int& row, int& columns) {
        int leftmost_column = -1;
        int left = 0, right = columns - 1, column;
        while (left <= right) {
            column = left + (right - left) / 2;
            if (binaryMatrix.get(row, column) == 1) {
                leftmost_column = column;
                right = column - 1;
            }
            else {
                left = column + 1;
            }
        }
        return leftmost_column;
    }
};
