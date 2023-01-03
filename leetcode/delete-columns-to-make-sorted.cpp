// 944. Delete Columns to Make Sorted
// https://leetcode.com/problems/delete-columns-to-make-sorted/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int column = 0; column < strs[0].size(); ++column) {
            for (int row = 1; row < strs.size(); ++row) {
                if (strs[row - 1][column] > strs[row][column]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
