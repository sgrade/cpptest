// 2566. Maximum Difference by Remapping a Digit
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> digits;
        int x = num;
        while (x) {
            int rem = x % 10;
            x /= 10;
            digits.emplace_back(rem);
        }
        reverse(digits.begin(), digits.end());
        
        int mx = 0, mn = 0, i = 0, digit;
        while (i < digits.size() && digits[i] == 9) {
            mx *= 10;
            mx += 9;
            ++i;
        }
        
        if (i != digits.size()){
            digit = digits[i];
            for (; i < digits.size(); ++i) {
                mx *= 10;
                if (digits[i] == digit)
                    mx += 9;
                else
                    mx += digits[i];
            }
        }

        digit = digits[0];
        for (int i = 0; i < digits.size(); ++i) {
            mn *= 10;
            if (digits[i] == digit)
                mn += 0;
            else
                mn += digits[i];
        }

        int ans = mx - mn;
        return ans;
    }
};
