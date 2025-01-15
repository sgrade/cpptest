// 2429. Minimize XOR
// https://leetcode.com/problems/minimize-xor/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Building the Answer
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        auto cnt1 = 0, cnt2 = __builtin_popcount(num2);

        int bit = 31, ans = 0;
        while (cnt1 < cnt2) {
            int current = 1 << bit;
            if (num1 & current || cnt2 - cnt1 > bit) {
                ans |= current;
                ++cnt1;
            }
            --bit;
        }
        return ans;
    }
};
