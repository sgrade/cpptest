// 258. Add Digits
// https://leetcode.com/problems/add-digits/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Mathematical: Digital Root
class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
};
