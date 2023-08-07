// 762. Prime Number of Set Bits in Binary Representation
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        while (left <= right) {
            int bits = CountSetBits (left);
            if (bits == 2 || bits == 3 || bits == 5 || bits == 7 || bits == 11 || bits == 13 || bits == 17 || bits == 19)
                ++ans;
                ++left;
        }
        return ans;
    }

private:
    int ans = 0;
    int CountSetBits(int n) {
            int count = 0;
            while (n) {
                count += n & 1;
                n >>= 1;
            }
            return count;
        }
};
