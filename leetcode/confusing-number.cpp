// 1056. Confusing Number
// https://leetcode.com/problems/confusing-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool confusingNumber(int n) {
        if (n == 0) return false;
        int tmp = n;
        int x, rotated_n = 0;
        while (tmp > 0 && tmp % 10 == 0) {
            tmp /= 10;
        }
        while (tmp > 0) {
            x = tmp % 10;
            tmp /= 10;
            if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7) {
                return false;
            }
            rotated_n *= 10;
            if (x == 6) x = 9;
            else if (x == 9) x = 6;
            rotated_n += x;
        }
        
        return rotated_n == n ? false : true;
    }
};
