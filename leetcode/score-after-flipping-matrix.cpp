// 861. Score After Flipping Matrix
// https://leetcode.com/problems/score-after-flipping-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int ones, zeroes;
        int num;

        for (int i=0; i <= n - 1; i++) {
            if (grid[i][0] == 1) continue;
            for (int j=0; j <= m - 1; j++) grid[i][j] = (grid[i][j] + 1)%2;
        }


        for (int j=1; j <= m - 1; j++) {
            ones = 0; zeroes = 0;
            for (int i=0; i <= n - 1; i++) {
                ones += (grid[i][j] == 1);
                zeroes += (grid[i][j] == 0);
            }
            if (ones < zeroes) {
                for (int i=0; i <= n - 1; i++) grid[i][j] = (grid[i][j] + 1)%2;
            }
        }

        for (int i=0; i <= n - 1; i++) {
            num = 0;
            for (int j=0; j <= m - 1; j++) {
                if (grid[i][j]) num |= (1<<(m - j - 1));
            }
            res += num;
        }

        return res;
    }
};
