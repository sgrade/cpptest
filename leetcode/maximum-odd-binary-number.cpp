// 2864. Maximum Odd Binary Number
// https://leetcode.com/problems/maximum-odd-binary-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end(), greater<>());
        auto pos = s.find_last_of('1');
        swap(s[pos], s.back());
        return s;
    }
};
