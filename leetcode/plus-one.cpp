// 66. Plus One
// https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        // Note: if carry == 0, the rest of the array won't change
        // So we stop iterating
        // Idea is from one of the leetcode's submissions
        for (int i = digits.size() - 1; i > -1 && carry > 0; --i) {
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
