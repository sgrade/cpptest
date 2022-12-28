// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) {
            return false;
        }
        int x = 1, mx_by_two = numeric_limits<int>::max() / 2;
        while (x < n && x <= mx_by_two) {
            x <<= 1;
        }
        return (x == n ? true : false);
    }
};
