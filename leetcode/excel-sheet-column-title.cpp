// 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int current_num;
        while (columnNumber > 0) {
            current_num = columnNumber % 26;
            ans += (current_num == 0 ? 'Z' : current_num + '@');
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
