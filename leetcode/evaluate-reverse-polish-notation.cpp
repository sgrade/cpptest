// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        stack<int> nums;
        int x, num1, num2;
        for (const string& s: tokens) {
            if (isdigit(s.back())) {
                x = stoi(s);
                nums.emplace(x);
            }
            else {
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                x = ops(s, num1, num2);
                nums.emplace(x);
            }
        }
        return nums.top();
    }
    
    int ops(const string &op, const int &num1, const int &num2) {
        int output;
        if (op == "+")
            output = num1 + num2;
        else if (op == "-")
            output = num1 - num2;
        else if (op == "*")
            output = num1 * num2;
        else
            output = num1 / num2;
        return output;
    }
};
