// 1056. Confusing Number
// https://leetcode.com/problems/confusing-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool confusingNumber(int n) {
        if (n == 0) return false;
        int x = n;
        vector<int> digits;
        unordered_set invalid = {2, 3, 4, 5, 7};
        while (x > 0) {
            digits.emplace_back(x % 10);
            x /= 10;
            if (invalid.find(digits.back()) != invalid.end()) {
                return false;
            }
        }
        int i = 0;
        while (digits[i] == 0) {
            ++i;
        }
        unordered_map<int, int> rotated = {
            {0, 0}, 
            {1, 1}, 
            {6, 9},
            {8, 8},
            {9, 6}
        };
        x = rotated[digits[i]];
        ++i;
        for (; i < digits.size(); ++i) {
            x *= 10;
            x += rotated[digits[i]];
        }
        return x == n ? false : true;
    }
};
