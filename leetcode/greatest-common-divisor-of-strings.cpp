// 1071. Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Greatest Common Divisor
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        int gcd_len = gcd (str1.size(), str2.size());
        return str1.substr(0, gcd_len);
    }
};
