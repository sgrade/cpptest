// 3133. Minimum Array End
// https://leetcode.com/problems/minimum-array-end/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Bitmasking with Logical Operations
class Solution {
public:
    long long minEnd(int n, int x) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        --n;
        long long ans = x, mask;
        for (mask = 1; n > 0; mask <<= 1) {
            if ((mask & x) == 0) {
                // Set the bit in ans based on the least significant bit of n
                ans |= (n & 1) * mask;
                n >>= 1;
            }
        }
        return ans;
    }
};
