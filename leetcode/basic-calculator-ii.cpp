// 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        vector<int> numbers;
        vector<char> operations;
        
        int i = s[0] == '-' ? 1 : 0;
        for (; i < s.size(); ++i) {
            if (!isdigit(s[i])) {
                if (isspace(s[i])) {
                    continue;
                }
                else {
                    operations.emplace_back(s[i]);
                }
            }
            else {
                int x = 0;
                while (true) {
                    x = x * 10 + (s[i] - '0');
                    if (i + 1 < s.size() && isdigit(s[i + 1])) {
                        ++i;
                    }
                    else {
                        break;
                    }
                }
                numbers.emplace_back(x);
            }
        }
        
        if (s[0] == '-') {
            numbers[0] *= -1;
        }
        
        int num_idx, ops_idx;
        
        for (ops_idx = 0; ops_idx < operations.size(); ++ops_idx) {
            if (operations[ops_idx] == '+' || operations[ops_idx] == '-') {
                continue;
            }
            else if (operations[ops_idx] == '*') {
                numbers[ops_idx + 1] *= numbers[ops_idx];
                
            }
            else if (operations[ops_idx] == '/') {
                numbers[ops_idx + 1] = numbers[ops_idx] / numbers[ops_idx + 1];
            }
            numbers[ops_idx] = 0;
            operations[ops_idx] = '_';
        }
        
        ops_idx = 0;
        while (ops_idx < operations.size() && operations[ops_idx] == '_') {
            ++ops_idx;
        }
        
        long ans = numbers[ops_idx];
        
        for (ops_idx = 0; ops_idx < operations.size(); ++ops_idx) {
            if (operations[ops_idx] == '_') {
                continue;
            }
            
            num_idx = ops_idx + 1;
            while (num_idx < operations.size() && operations[num_idx] == '_') {
                ++num_idx;
            }
            
            if (operations[ops_idx] == '+') {
                ans += numbers[num_idx];
            }
            else if (operations[ops_idx] == '-' ) {
                ans -= numbers[num_idx];
            }
        }
        
        return (int)ans;
    }
};
