// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Sort by Row
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int n = s.size();
        vector<string> rows(min(numRows, n));
        
        int current_row = 0;
        bool going_down = false;
        
        for (const char &c: s) {
            rows[current_row] += c;
            if (current_row == 0 || current_row == numRows - 1) {
                going_down = !going_down;
            }
            current_row += going_down ? 1 : -1;
        }
        
        string ans;
        for (const string &row: rows) 
            ans += row;
        
        return ans;
    }
};
