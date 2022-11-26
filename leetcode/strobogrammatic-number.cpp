// 246. Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        unordered_map<char, char> strobs = {
            {'8', '8'}, 
            {'9', '6'},
            {'6', '9'},
            {'1', '1'},
            {'0', '0'}
        };
        return backtrack(num, n, 0, strobs);
    }
private:
    bool backtrack(const string &num, const int &n, const int left, unordered_map<char, char> &strobs) {
        if (left > n - left - 1) {
            return true;
        }
        if (num[n - left - 1] != strobs[num[left]]) {
            return false;
        }
        return backtrack(num, n, left + 1, strobs);
    }
};
