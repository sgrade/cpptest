// 1432. Max Difference You Can Get From Changing an Integer
// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;
        int x = num;
        while (x) {
            int rem = x % 10;
            x /= 10;
            digits.emplace_back(rem);
        }
        reverse(digits.begin(), digits.end());
        
        int mx = 0, mn = 0, i = 0, digit_to_swap;
        while (i < digits.size() && digits[i] == 9) {
            mx *= 10;
            mx += 9;
            ++i;
        }
        
        if (i != digits.size()){
            digit_to_swap = digits[i];
            for (; i < digits.size(); ++i) {
                mx *= 10;
                if (digits[i] == digit_to_swap)
                    mx += 9;
                else
                    mx += digits[i];
            }
        }

        i = 0, digit_to_swap = -1;
        while (i < digits.size() && digits[i] < 2) {
            mn *= 10;
            mn += digits[i];
            ++i;
        }
        if (i != digits.size()) {   // if num != (1)
            digit_to_swap = digits[i];
            int mn_digit = i == 0 ? 1 : 0;
            for (; i < digits.size(); ++i) {
                mn *= 10;
                if (digits[i] == digit_to_swap)
                    mn += mn_digit;
                else
                    mn += digits[i];
            }
        }

        int ans = mx - mn;
        return ans;
    }
};
