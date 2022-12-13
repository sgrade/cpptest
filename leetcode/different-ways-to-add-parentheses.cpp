// 241. Different Ways to Add Parentheses
// https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/different-ways-to-add-parentheses/solutions/66331/c-4ms-recursive-dp-solution-with-brief-explanation/
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> dp;
        return Compute(expression, dp);
    }
private:
    vector<int> Compute(const string& expression, unordered_map<string, vector<int>>& dp) {
        vector<int> ans;
        int n = expression.size();
        for (int i = 0; i < n; ++i) {
            char oper = expression[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> left, right;

                string s = expression.substr(0, i);
                if (dp.find(s) != dp.end()) 
                    left = dp[s];
                else 
                    left = Compute(s, dp);

                s = expression.substr(i + 1);
                if (dp.find(s) != dp.end()) 
                    right = dp[s];
                else 
                    right = Compute(s, dp);

                for (const int &x: left) {
                    for (const int &y: right) {
                        if (oper == '+') 
                            ans.emplace_back(x + y);
                        else if (oper == '-')
                            ans.emplace_back(x - y);
                        else {
                            ans.emplace_back(x * y);
                        }
                    }
                }
            }
        }
        if (ans.empty()) 
            ans.emplace_back(atoi(expression.c_str()));
        dp[expression] = ans;
        return ans;
    }
};
