// 247. Strobogrammatic Number II
// https://leetcode.com/problems/strobogrammatic-number-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<char>> reversible_pairs = {
        {'0', '0'}, {'1', '1'}, 
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    
    vector<string> findStrobogrammatic(int n) {
        return generate(n, n);
    }
    
    vector<string> generate(int len, const int& n) {
        if (len == 0) {
            return {""};
        }
        
        else if (len == 1) {
            return {"0", "1", "8"};
        }
        
        vector<string> prev = generate(len - 2, n);
        vector<string> cur;
        for (string &s: prev) {
            for (vector<char>& p: reversible_pairs) {
                if (p[0] != '0' || len != n) {
                    cur.push_back(p[0] + s + p[1]);
                }
            }
        }
        return cur;
    }
};
