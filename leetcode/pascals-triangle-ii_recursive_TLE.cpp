// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/
// TLE

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            ans[i] = getNum(rowIndex, i);
        }
        return ans;
    }
    
    int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col) {
            return 1;
        }
        return getNum(row - 1, col - 1) + getNum (row - 1, col);
    }
};



int main() {

    Solution sol;
    vector<int> a = sol.getRow(3);
    for (int &el: a) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}
