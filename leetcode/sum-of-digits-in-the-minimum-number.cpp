// 1085. Sum of Digits in the Minimum Number
// https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum % 2 == 0;
    }
};
