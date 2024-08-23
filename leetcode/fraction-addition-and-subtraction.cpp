// 592. Fraction Addition and Subtraction
// https://leetcode.com/problems/fraction-addition-and-subtraction/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2 - Parsing with Regular Expressions
class Solution {
public:
    string fractionAddition(string expression) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int num = 0, denom = 1;
        vector<string> nums;
        int i = 0;
        if (expression[0] != '-')
            expression = '+' + expression;
        int n = expression.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && expression[j] != '+' && expression[j] != '-')
                ++j;
            nums.emplace_back(expression.substr(i, j - i));
            i = j;
        }

        for (int i = 0; i < nums.size(); ++i) {
            size_t pos = nums[i].find('/');
            int cur_num = stoi(nums[i].substr(1, pos - 1));
            if (nums[i][0] == '-')
                cur_num = -cur_num;
            int cur_denom = stoi(nums[i].substr(pos + 1));
            num = num * cur_denom + cur_num * denom;
            denom = denom * cur_denom;
            int gcd = abs(GetGCD(num, denom));
            num /= gcd;
            denom /= gcd;
        }
        
        return  to_string(num) + "/" + to_string(denom);
    }

private:
    int GetGCD (int a, int b) {
        if (a == 0)
            return b;
        return GetGCD(b % a, a);
    }
};
