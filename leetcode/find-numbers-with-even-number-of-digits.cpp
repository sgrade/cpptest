// 1295. Find Numbers with Even Number of Digits
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int ans = 0;
            for (int& num: nums) {
                int digits = 0;
                while (num) {
                    num /= 10;
                    ++digits;
                }
                ans += digits % 2 == 0;
            }
            return ans;
        }
    };
