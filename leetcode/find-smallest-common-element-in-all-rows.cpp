// 1198. Find Smallest Common Element in All Rows
// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        list<int> common;
        
        int i = 0, j = 0;
        while (i < cols && j < cols) {
            if (mat[0][i] == mat[1][j]) {
                common.emplace_back(mat[0][i]);
                ++i;
                ++j;
            }
            else if (mat[0][i] < mat[1][j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        
        list<int>::iterator cit;
        for (i = 2; i < rows; ++i) {
            cit = common.begin();
            j = 0;
            while (cit != common.end() && j < cols) {
                if (mat[i][j] == *cit) {
                    ++cit;
                    ++j;
                }
                else if (mat[i][j] < *cit) {
                    ++j;
                }
                else {
                    common.erase(cit++);
                }
            }
        }
        
        if (common.empty()) {
            return -1;
        }
        return common.front();
    }
};
