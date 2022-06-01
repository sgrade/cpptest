// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp;
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 2 - 1) / 2; ++j) {
                tmp = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = tmp;
            }
        }
    }
};


int main() {



    return 0;
}