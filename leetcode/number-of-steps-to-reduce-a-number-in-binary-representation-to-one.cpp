// 1404. Number of Steps to Reduce a Number in Binary Representation to One
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), ans = 0, carry = 0, last;
        for (int i = n - 1; i > 0; --i) {
            last = (s[i] - '0') + carry;
            if (last % 2 == 1) {
                ans += 2;
                carry = 1;
            }
            else
                ++ans;
        }
        return ans + carry;
    }
};
