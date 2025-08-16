// 1323. Maximum 69 Number
// https://leetcode.com/problems/maximum-69-number/

#include <vector>
#include <cmath>


class Solution {
 public:
    int maximum69Number(int num) {
        int n = num, pos = -1, i = 0;
        int temp = n;
        // Find the leftmost 6
        while (temp > 0) {
            if (temp % 10 == 6) {
                pos = i;
            }
            temp /= 10;
            ++i;
        }
        if (pos == -1) {
            return num;
        }
        // Change the leftmost 6 to 9
        return num + 3 * static_cast<int>(pow(10, pos));
    }
};
