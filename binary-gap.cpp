// Based on Approach 2: One Pass
// https://leetcode.com/problems/binary-gap/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, prev = -1;
        for (int i = 0; n > 0 && i < 32; ++i) {
            if (n & 1) {
                if (prev >= 0)
                    ans = max(ans, i - prev);
                prev = i;
            }
            n = n >> 1;
        }
        return ans;
    }
};
