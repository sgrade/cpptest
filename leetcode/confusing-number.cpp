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
        unordered_set invalid = {2, 3, 4, 5, 7};
        unordered_map<int, int> rotated = {
            {0, 0}, 
            {1, 1}, 
            {6, 9},
            {8, 8},
            {9, 6}
        };
        while (tmp > 0 && tmp % 10 == 0) {
            tmp /= 10;
        }
        while (tmp > 0) {
            x = tmp % 10;
            tmp /= 10;
            if (invalid.find(x) != invalid.end()) {
                return false;
            }
            rotated_n *= 10;
            rotated_n += rotated[x];
        }
        
        return rotated_n == n ? false : true;
    }
};
