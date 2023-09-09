// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans {{1}};
        for (int i = 1; i < numRows; ++i) {
            ans.emplace_back(vector<int>(i + 1));
            ans[i][0] = 1;
            for (int j = 1; j < i; ++j)
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            ans[i].back() = 1;
        }
        return ans;
    }
};
