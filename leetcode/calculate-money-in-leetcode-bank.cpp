// 1716. Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int rem = n % 7;
        return (56 + 7 * (weeks - 1)) * weeks / 2 + (1 + weeks + weeks + rem) * rem / 2;
    }
};
