// 2843. Count Symmetric Integers
// https://leetcode.com/problems/count-symmetric-integers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Enumeration
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for (int x = low; x <= high; ++x) {
                if (x < 100 && x % 11 == 0)
                    ++ans;
                else if (x >= 1000 && x < 10000) {
                    int left = x / 1000 + (x % 1000) / 100;
                    int right = (x % 100) / 10 + x % 10;
                    ans += left == right;
                }
            }
            return ans;
        }
    };
